#include "ArduinoNvs.h"
#include "html.h"
#include "ota.h"

ota_web ota;
int a = 0;
WebServer server(80);

void handleRoot() { // root of server
    server.send(200, "html", html_menu);
}

void handleTemp() { // temp
    a++;
    char str[10];
    sprintf(str, "%d", a);
    server.send(200, "text", str);
}

void handleWifi() { server.send(200, "html", html_login); }

void getWifiData() {
    String ssid = server.arg(0);
    String password = server.arg(1);
    NVS.setString("ssid", ssid);
    NVS.setString("password", password);

    String tmp = ssid + "--" + password;
    server.send(200, "text", tmp);
}

void setup() {
    Serial.begin(115200);

    NVS.begin(); // NVS need remodel
    NVS.setString("ssid", "Bspot0856_2.4_plus");
    NVS.setString("password", "7C000856");
    char ssid[30];
    strcpy(ssid, NVS.getString("ssid").c_str());
    char password[30];
    strcpy(password, NVS.getString("password").c_str());

    //.SSID = "Bspot0856_2.4_plus", .password = "7C000856"
    wifi w = {.SSID = ssid, .password = password};
    ota.wifiConnect(w);
    ota.otaBegin();
    MDNS.begin("esp32");
    
    server.on("/", handleRoot);
    server.on("/wifi/data", getWifiData);
    server.on("/wifi", handleWifi);
    server.on("/temp", handleTemp);
    server.begin();

    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    ota.checkForOTA();
    server.handleClient();
    delay(300);
}
