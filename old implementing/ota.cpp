#include "ota.h"

bool ota_web::wifiConnect(wifi aut) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(aut.SSID, aut.password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        return false;
    }
    return true;
}

void ota_web::otaBegin() { // pass argumant of type function for start end prograess and error
    ArduinoOTA
        .onStart([]() {
            String type;
            if (ArduinoOTA.getCommand() == U_FLASH)
                type = "sketch";
            else // U_SPIFFS
                type = "filesystem";
        })
        .onEnd([]() {
            // Serial.println("\nEnd");
        })
        .onProgress([](unsigned int progress, unsigned int total) {
            // Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
        })
        .onError([](ota_error_t error) {
            // Serial.printf("Error[%u]: ", error);
            // if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
            // else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
            // else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
            // else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
            // else if (error == OTA_END_ERROR) Serial.println("End Failed");
        });

    ArduinoOTA.begin();
}

void ota_web::checkForOTA() { ArduinoOTA.handle(); }
