# IR remote server running on esp8266
```this project is written for the arduino ide```

# How to use
## schematic
![schematic](https://github.com/ishay320/esp8266_IRremote/blob/main/data/schematics.jpg)

and for connecting to the internet swap inside `esp8266_IRremote.ino` 
``` C
const char* ssid = "ssid";
const char* password = "pass";
```
to your wifi.

if you wish to connect the LED to different pin its in:
``` C
const uint16_t kIrLed = 4; 
```

if you want to send sensor data to the user add it to function `handleSendData()`


## the project goals:
* Running server
* Controll IR
* Reconfigure the WIFI on the fly
* To be able to add more sensors or controllers
* full OTA support

## done:
* Running server
* Controll IR
* full OTA support via arduinoIDE
