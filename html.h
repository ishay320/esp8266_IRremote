#include <stdint.h>

const char html_login[] = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>Wifi Config</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
</head>
<body>
    <h2>Welcome to WIFI connection and OTA</h2>
<form action="/data" method="POST">
  <label for="ssid">WIFI SSID:</label>
  <input type="text" id="ssid" name="ssid"><br><br>
  <label for="password">WIFI password:</label>
  <input type="password" id="password" name="password" ><br><br>
  <input type="submit" value="Submit">
</form>
</body>
</html>
)=====";

const char html_menu[] = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>menu</title>
</head>

<body>
    <h2>Welcome to esp server</h2>
    <form action="/wifi">
        <input type="submit" value="wifi config" />
    </form>
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

</html>

)=====";
