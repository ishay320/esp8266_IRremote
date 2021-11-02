#pragma once

#include <ArduinoOTA.h>
#include <ESPmDNS.h>
#include <WebServer.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

struct wifi {
    char *SSID;
    char *password;
};

class ota_web {
  private:
  public:
    bool wifiConnect(wifi aut);

    void otaBegin(); // pass argumant of type function for start end prograess and error
    // String getIP(){
    //   return WiFi.localIP();
    // }

    void checkForOTA();
};
