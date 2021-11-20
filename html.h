/* 
do not edit this file,
1. edit files in folder html_files 
2. run make_html.py
*/
#include <stdint.h>

const char html_IRController[] = R"=====(<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IR controller</title>
</head>

<body>
    <form action="/irSend" method="GET">
        <label for="protocol">protocol</label>
        <input type="number" id="protocol" name="protocol" value="18"><br><br>
        <label for="model">model</label>
        <input type="number" id="model" name="model" value="1"><br><br>
        <label for="mode">mode</label>
        <select id="mode" name="mode">
            <option value="-1">Off</option>
            <option value="0" selected="selected">Auto</option>
            <option value="1">Cool</option>
            <option value="2">Heat</option>
            <option value="3">Dry</option>
            <option value="4">Fan</option>
        </select><br><br>
        <label for="celsius">celsius</label>
        <input type="hidden" name="celsius" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="degrees">degrees</label>
        <input type="number" id="degrees" name="degrees" value="23"><br><br>
        <label for="fanspeed">fanspeed</label>
        <select id="fanspeed" name="fanspeed">
            <option value="0">Auto</option>
            <option value="1">Min</option>
            <option value="2">Low</option>
            <option value="3">Medium</option>
            <option value="4">High</option>
            <option value="5">Max</option>
        </select><br><br>
        <label for="swingv">swingv</label>
        <select id="swingv" name="swingv">
            <option value="-1">Off</option>
            <option value="0">Auto</option>
            <option value="1">Highest</option>
            <option value="2">High</option>
            <option value="3">Middle</option>
            <option value="4">Low</option>
            <option value="5">Lowest</option>
        </select><br><br>
        <label for="swingh">swingh</label>
        <select id="swingh" name="swingh">
            <option value="-1">Off</option>
            <option value="0">Auto</option>
            <option value="1">LeftMax</option>
            <option value="2">Left</option>
            <option value="3">Middle</option>
            <option value="4">Right</option>
            <option value="5">RightMax</option>
            <option value="5">Wide</option>
        </select><br><br>
        <label for="light">light</label>
        <input type="hidden" name="light" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="beep">beep</label>
        <input type="hidden" name="beep" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="econo">econo</label>
        <input type="hidden" name="econo" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="filter">filter</label>
        <input type="hidden" name="filter" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="turbo">turbo</label>
        <input type="hidden" name="turbo" value="0"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value"><br><br>
        <label for="quiet">quiet</label>
        <input type="hidden" name="quiet" value="0"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value"><br><br>
        <label for="sleep">sleep</label>
        <input type="number" id="sleep" name="sleep" value="-1"><br><br>
        <label for="clean">clean</label>
        <input type="hidden" name="clean" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="clock">clock</label>
        <input type="number" id="clock" name="clock" value="-1"><br><br>
        <label for="power">power</label>
        <input type="hidden" name="power" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <input type="submit" value="Submit">
    </form>

    <form action="/">
        <br>
        <button>back to menu</button>
    </form>


    <!-- TODO: add sensor -->
    <script>
        setInterval(function () {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    var temp = this.responseText;
                    document.getElementById("temp").textContent = temp;
                }
            };
            xhttp.open("GET", "/temp", true);
            xhttp.send();
        }, 1000);
    </script>
</body>

</html>)=====";

const char html_menu[] = R"=====(<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>menu</title>
</head>

<body>
    <h2>Welcome to esp server</h2>

    <form action="/irController">
        <br>
        <button>IR Controller</button>

    </form>

    <form action="/wifiLogin">
        <br>
        <button>WIFI Setting</button>
    </form>
    <div>sensor data:</div>
    <div id="temp">
        124243
    </div>
    <script>
        setInterval(function () {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    var temp = this.responseText;
                    document.getElementById("temp").textContent = temp;
                }
            };
            xhttp.open("GET", "/temp", true);
            xhttp.send();
        }, 1000);


    </script>


</body>

</html>)=====";

const char html_wifiLogin[] = R"=====(<!DOCTYPE html>
<html>

<head>
  <meta charset='utf-8'>
  <meta http-equiv='X-UA-Compatible' content='IE=edge'>
  <title>Wifi Config</title>
  <meta name='viewport' content='width=device-width, initial-scale=1'>
</head>

<body>
  <h2>WIFI connection setting</h2>
  <!-- back button -->
  <form action="/wifiInfo" method="POST">
    <!-- dropdown by the board search -->
    <label for="ssid">WIFI SSID:</label>
    <select id="mode" name="mode">

    </select><br><br>
    <label for="password">WIFI password:</label>
    <input type="password" id="password" name="password"><br><br>
    <input type="submit" value="set">
  </form>

  <form action="/">
    <br>
    <button>back to menu</button>

  </form>

  <script>

    function updateList() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          let message = this.responseText;
          let ssid = JSON.parse(message).SSID;
          let list = document.getElementById("mode");
          for (let index = 0; index < ssid.length; index++) {
            option = document.createElement('option');
            option.value = option.text = ssid[index];
            list.add(option);
          }
        }
      };
      xhttp.open("GET", "/getWireless", true);
      xhttp.send();
    }

    function remove() { // not working
      var selectObject = document.getElementById("mode");
      for (var i = 0; i < selectObject.length; i++) {
        selectObject.remove(i);
      }
    }

    updateList();

  </script>
</body>

</html>)=====";

