#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <IRremoteESP8266.h>
#include <IRac.h>
#include <IRutils.h>

#include "html.h"

const char* ssid = "ssid";
const char* password = "pass";

int a = 0; // for checking how many masseges sended in handleSendData()
ESP8266WebServer server(80);

const uint16_t kIrLed = 4;  // The ESP GPIO pin to use that controls the IR LED.
IRac ac(kIrLed);  // Create a A/C object using GPIO to sending messages with.


void handleLedProg(){ // gets what to output via the IR
  if(server.args()!=18){
    return;
  }
  ac.next.protocol = (decode_type_t)atoi(server.arg(0).c_str());
  ac.next.model = atoi(server.arg(1).c_str());
  ac.next.mode = (stdAc::opmode_t)atoi(server.arg(2).c_str());
  ac.next.celsius = atoi(server.arg(3).c_str());
  ac.next.degrees = atoi(server.arg(4).c_str());
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
  ac.next.clock = atoi(server.arg(16).c_str());  //-1 for off
  ac.next.power = atoi(server.arg(17).c_str());
  ac.sendAc();  // Send the message.
  server.send(200, "text", "sent seccesfuly!");
}

void handleSendData(){ // for sending data like sensors etc
  a++;
  char str[10];
  sprintf(str, "%d", a);
  server.send(200, "text", str);
}

void handleRoot(){ // root of server
    server.send(200, "html", html_IRController);
}

//********************** setup ************//
void setup() {
    Serial.begin(115200);
    delay(200);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    { 
    }
    
   ArduinoOTA.onStart([]() {
   Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
   Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.print("\e[2K");
   Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
   Serial.printf("Error[%u]: ", error);
   if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
   else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
   else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
   else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
   else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/temp",handleSendData);
  server.begin();
  server.on("/", handleRoot);
  server.on("/irSend",handleLedProg);
  server.begin();

  // Set up what we want to send via the IR.
  // See state_t, opmode_t, fanspeed_t, swingv_t, & swingh_t in IRsend.h for
  // all the various options.
  ac.next.protocol = (decode_type_t)18; //decode_type_t::DAIKIN;  // Set a protocol to use.
  ac.next.model = 1;  // Some A/Cs have different models. Try just the first.
  ac.next.mode = stdAc::opmode_t::kCool;  // Run in cool mode initially.
  ac.next.celsius = true;  // Use Celsius for temp units. False = Fahrenheit
  ac.next.degrees = 23;  // 25 degrees.
  ac.next.fanspeed = stdAc::fanspeed_t::kMedium;  // Start the fan at medium.
  ac.next.swingv = stdAc::swingv_t::kOff;  // Don't swing the fan up or down.
  ac.next.swingh = stdAc::swingh_t::kOff;  // Don't swing the fan left or right.
  ac.next.light = true;  // any LED/Lights/Display that we can.
  ac.next.beep = true;  // any beep from the A/C if we can.
  ac.next.econo = true;  // economy modes if we can.
  ac.next.filter = true;  // Ion/Mold/Health filters if we can.
  ac.next.turbo = false;  // Don't use any turbo/powerful/etc modes.
  ac.next.quiet = false;  // Don't use any quiet/silent/etc modes.
  ac.next.sleep = -1;  // Don't set any sleep time or modes.
  ac.next.clean = true;  // Turn off any Cleaning options if we can.
  ac.next.clock = -1;  // Don't set any current time if we can avoid it.
  ac.next.power = false;  // Initially start with the unit off.
}

void loop() {
  ArduinoOTA.handle();
  server.handleClient();

}
