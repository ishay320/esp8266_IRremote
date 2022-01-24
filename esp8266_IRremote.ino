// TODO: spiff: https://techtutorialsx.com/2018/09/17/esp32-arduino-web-server-serving-external-css-file/
#include <ArduinoOTA.h>
#include <EEPROM.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

#include <IRac.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>

#include "html.h"

#define LED 16
#define SSID_POS 0
#define CONNECTION_TIME_TRY 50
const char *ssid = "ssid";
const char *password = "pass";

typedef struct {
    String ssid;
    String password;
} wifi_login;

int a = 0; // for checking how many masseges sended in handleSendData()
ESP8266WebServer server(80);

const uint16_t kIrLed = 4; // The ESP GPIO pin to use that controls the IR LED.
IRac ac(kIrLed);           // Create a A/C object using GPIO to sending messages with.
int protocol_index = 0;
double Thermistor(int RawADC) {
    double Temp;
    Temp = log(((10240000 / RawADC) - 9000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
    Temp = Temp - 273.15; // Convert Kelvin to Celcius
    return Temp;
}

void handleLedProg() { // gets what to output via the IR
    if (server.args() != 18) {
        printf("ERROR: failed in handleLedProg\n");
        return;
    }
    ac.next.protocol = (decode_type_t)atoi(server.arg(0).c_str());
    ac.next.model = atoi(server.arg(1).c_str());
    ac.next.mode = (stdAc::opmode_t)atoi(server.arg(2).c_str());
    ac.next.celsius = atoi(server.arg(3).c_str());
    ac.next.degrees = (float)atof(server.arg(4).c_str()); // TODO: fix degree always 20
    ac.next.fanspeed = (stdAc::fanspeed_t)atoi(server.arg(5).c_str());
    ac.next.swingv = (stdAc::swingv_t)atoi(server.arg(6).c_str());
    ac.next.swingh = (stdAc::swingh_t)atoi(server.arg(7).c_str());
    ac.next.light = atoi(server.arg(8).c_str());
    ac.next.beep = atoi(server.arg(9).c_str());
    ac.next.econo = atoi(server.arg(10).c_str());
    ac.next.filter = atoi(server.arg(11).c_str());
    ac.next.turbo = atoi(server.arg(12).c_str());
    ac.next.quiet = atoi(server.arg(13).c_str());
    ac.next.sleep = atoi(server.arg(14).c_str()); //-1 for off
    ac.next.clean = atoi(server.arg(15).c_str());
    ac.next.clock = atoi(server.arg(16).c_str()); //-1 for off
    ac.next.power = atoi(server.arg(17).c_str());
    ac.sendAc(); // Send the message.
    server.send(200, "text", "sent seccesfuly!");
}

void handleSendData() { // for sending data like sensors etc
    double sensorValue = 0;
    for (size_t i = 0; i < 10; i++) {
        sensorValue += Thermistor(analogRead(A0));
    }
    sensorValue /= 10;
    String s = String(sensorValue, 3);
    server.send(200, "text", s);
}

void handleRoot() { // root of server
    server.send(200, "html", html_menu);
}
void handleTest() {
    for (;;) {
        if (protocol_index == kLastDecodeType) {
            protocol_index = 0;
            printf("reset\n");
        }
        protocol_index++;
        decode_type_t protocol = (decode_type_t)protocol_index;
        // If the protocol is supported by the IRac class ...
        if (ac.isProtocolSupported(protocol)) {
            Serial.println("Protocol " + String(protocol) + " / " + typeToString(protocol) + " is supported.");
            String out = String("Protocol : " + String(protocol) + " / " + typeToString(protocol) + protocol_index);
            server.send(200, "html", out);
            ac.next.protocol = protocol; // Change the protocol used.
            ac.next.power = true;        // We want to turn on the A/C unit.
            Serial.println("Sending a message to turn ON the A/C unit.");
            ac.sendAc();           // Have the IRac class create and send a message.
            delay(5000);           // Wait 5 seconds.
            ac.next.power = false; // Now we want to turn the A/C off.
            Serial.println("Send a message to turn OFF the A/C unit.");
            ac.sendAc(); // Send the message.
            delay(1000); // Wait 1 second.
            break;
        }
    }
}

void handleIRController() { // IR controller
    server.send(200, "html", html_IRController);
}

void handleIRControllerJS() { // IR controller js
    server.send(200, "html", IRcontroller);
}

void handleLogin() { // wifi setting
    server.send(200, "html", html_wifiLogin);
}

void handleStyle() { // style.css
    server.send(200, "text/css", style);
}

void handleSSIDData() { // wifi setting
    wifi_login wifi = {.ssid = server.arg(0).c_str(), .password = server.arg(1).c_str()};
    Serial.printf("ssid %s, pass %s\n", wifi.ssid, wifi.password);
    // EEPROM.put(SSID_POS, wifi);
    // EEPROM.commit();
    server.send(200, "html", "trying to connect");
    // ESP.restart();
    WiFi.disconnect();
    tryToConnect(server.arg(0), server.args() == 2 ? server.arg(1) : "");
}

void handleGetWireless() { // search for networks and send them to the client
    int n = WiFi.scanNetworks();
    String s = "{\"SSID\":[";
    for (size_t i = 0; i < n; i++) {
        s += "\"";
        s += WiFi.SSID(i);
        s += "\"";
        if (i != n - 1) {
            s += ",";
        }
    }
    s += "]}";
    server.send(200, "json", s);
}
void tryToConnect(String s, String p) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(s, p);
    int time_to_connect = 0;
    bool not_connected = false;
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
        if (time_to_connect++ == CONNECTION_TIME_TRY * 10) {
            not_connected = true;
            break;
        }
    }
    Serial.printf("status: %d,%d\n", WiFi.status(), WL_CONNECT_FAILED);
    if (not_connected) {
        WiFi.disconnect();
        Serial.printf("status: %d,%d\n", WiFi.status(), WL_CONNECT_FAILED);
        IPAddress local_IP(192, 168, 4, 22);
        IPAddress gateway(192, 168, 4, 9);
        IPAddress subnet(255, 255, 255, 0);
        WiFi.mode(WIFI_AP);

        Serial.print("Setting soft-AP configuration ... ");
        Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

        Serial.print("Setting soft-AP ... ");
        Serial.println(WiFi.softAP("ESP8266_IR") ? "Ready" : "Failed!");

        Serial.print("Soft-AP IP address = ");
        Serial.println(WiFi.softAPIP());
    } else {
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
}

//********************** setup ************//
void setup() {
    Serial.begin(115200);
    delay(2000);
    pinMode(LED, OUTPUT);
    digitalWrite(16, HIGH);

    // wifi_login log{.ssid = "", .password = ""};
    // EEPROM.begin(512); // Initialize EEPROM
    // TODO:#8 make it not crush
    // EEPROM.get(SSID_POS, log);
    // Serial.printf("ssid %s, pass %s\n", log.ssid, log.password);

    tryToConnect(ssid, password);

    ArduinoOTA.onStart([]() { Serial.println("Start"); });
    ArduinoOTA.onEnd([]() { Serial.println("\nEnd"); });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.print("\e[2K");
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR)
            Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR)
            Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR)
            Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR)
            Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR)
            Serial.println("End Failed");
    });
    ArduinoOTA.begin();

    server.begin();
    server.on("/", handleRoot);

    server.on("/irController", handleIRController);
    server.on("/IRcontroller.js", handleIRControllerJS);

    server.on("/wifiLogin", handleLogin);

    server.on("/irSend", handleLedProg);
    server.on("/test", handleTest);
    server.on("/wifiInfo", handleSSIDData);

    server.on("/temp", handleSendData);
    server.on("/getWireless", handleGetWireless);

    server.on("/style.css", handleStyle);
    server.begin();

    // Set up what we want to send via the IR.
    // See state_t, opmode_t, fanspeed_t, swingv_t, & swingh_t in IRsend.h for
    // all the various options.
    ac.next.protocol = (decode_type_t)18;          // decode_type_t::DAIKIN;  // Set a protocol to use.
    ac.next.model = 1;                             // Some A/Cs have different models. Try just the first.
    ac.next.mode = stdAc::opmode_t::kCool;         // Run in cool mode initially.
    ac.next.celsius = true;                        // Use Celsius for temp units. False = Fahrenheit
    ac.next.degrees = 23;                          // 25 degrees.
    ac.next.fanspeed = stdAc::fanspeed_t::kMedium; // Start the fan at medium.
    ac.next.swingv = stdAc::swingv_t::kOff;        // Don't swing the fan up or down.
    ac.next.swingh = stdAc::swingh_t::kOff;        // Don't swing the fan left or right.
    ac.next.light = true;                          // any LED/Lights/Display that we can.
    ac.next.beep = true;                           // any beep from the A/C if we can.
    ac.next.econo = true;                          // economy modes if we can.
    ac.next.filter = true;                         // Ion/Mold/Health filters if we can.
    ac.next.turbo = false;                         // Don't use any turbo/powerful/etc modes.
    ac.next.quiet = false;                         // Don't use any quiet/silent/etc modes.
    ac.next.sleep = -1;                            // Don't set any sleep time or modes.
    ac.next.clean = true;                          // Turn off any Cleaning options if we can.
    ac.next.clock = -1;                            // Don't set any current time if we can avoid it.
    ac.next.power = false;                         // Initially start with the unit off.
}
bool led = false;
void loop() {
    digitalWrite(LED, LOW);
    digitalWrite(LED, HIGH);
    led = !led;
    ArduinoOTA.handle();
    server.handleClient();
}
