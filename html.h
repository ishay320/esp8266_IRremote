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
    <link rel="stylesheet" type="text/css" href="style.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    <script src="IRcontroller.js" defer></script>
    <title>IR controller</title>
</head>

<body>
    <h1 class="title">IR controller</h1>
    <div class="body">
        <div class="card-grid" id="card-grid">

        </div>
        <div class="card-grid" id="card-grid2">

        </div>
    </div>
    <script>
        function myFunction() {
            var x = document.getElementById("myDIV");
            if (x.style.display === "none") {
                x.style.display = "block";
            } else {
                x.style.display = "none";
            }
        }
    </script>

    <!-- <form action="/irSend" method="GET">
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
    </form> -->

    <form action="/">
        <br>
        <button>back to menu</button>
    </form>


    <!-- TODO: add sensor -->
    <!-- <script>
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
    </script> -->
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
  <link rel="stylesheet" href="style.css">
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

const char style[] = R"=====(:root {
    --bg-color: lightblue;
    background-color: var(--bg-color);
    font-size: 2vw;
}
.title {
    position: sticky;
    background-color: var(--bg-color);
    color: black;
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    font-size: 3em;
    text-align: center;
    top: 0;
    margin-top: 0;
    margin-bottom: 0;
    width: 100%;
    z-index: 1;
}
.body {
    padding: 10px;
    display: flex;
    flex-direction: column;
    /* justify-content: center; */
    align-items: center;
}
.card-grid{
    display: grid;
    grid-template-columns: auto auto;
    font-size: 2em;
}
.card {
    margin: 5px;
    background-color: grey;
    padding: 5px 10px 10px 10px; 
    border-radius: 10px;
    border: 2px solid grey;
    transition-duration: 0.4s;
    color: white; 
    cursor: pointer;
}
.card:hover {
    background-color: lightgray;
    text-shadow: 5px 5px 6px rgb(63, 62, 62);
}

i.card-icon {
    position: relative;
    translate: 50px;
    font-size: 1em;
    top: 0.2em;
}
.card-slider {
    transition-duration: 0.4s;
    font-size: 0.5em;
    width:40vw;
}
.card-slider:hover {
    background-color: rgb(110, 110, 110);
    text-shadow: 5px 5px 6px rgb(63, 62, 62);
}
.slider-number{
    margin: 1em;
}
.slider {
    margin: 5px;
    -webkit-appearance: none;
    width: 100%;
    height: 15px;
    border-radius: 5px;
    background: #f5f5f5;
    outline: none;
    opacity: 0.7;
    -webkit-transition: .2s;
    transition: opacity .2s;
}
.slider:hover {
    opacity: 1;
}   
.slider::-webkit-slider-thumb{
    -webkit-appearance: none;
    appearance: none;
    width: 25px;
    height: 25px;
    border-radius: 50%; 
    background: #222222;
    cursor: pointer;
})=====";

const char IRcontroller[] = R"=====(// TODO:
// - make the slider integrated to the rest (2 colum of button 1 for slider)
// - hide unwanted buttons (add hide to db?)
// - make the switches work with more icons (add array to icons arr?)
// - DB check the real values

var ACproperty = {
    "protocol": {//X
        "active": 18,
        "type": "range-int",
        "range-int": [1, 100] //TODO: enter the real value
    },
    "model": { //X
        "active": 1,
        "type": "range-int",
        "range-int": [1, 100] //TODO: enter the real value
    },
    "mode": {
        "active": "Off",
        "type": "switch",
        "switch": {
            "Off": -1,
            "Auto": 0,
            "Cool": 1,
            "Heat": 2,
            "Dry": 3,
            "Fan": 4
        },
    },
    "celsius": {
        "active": 1,
        "type": "bool",
        "bool": 0,
    },
    "degrees": { //X
        "active": 26,
        "type": "range-float",
        "range-float": [16, 40]
    },
    "fanspeed": {
        "active": "Auto",
        "type": "switch",
        "switch": {
            "Auto": 0,
            "Min": 1,
            "Low": 2,
            "Medium": 3,
            "High": 4,
            "Max": 5
        }
    },
    "swingv": {
        "active": "Off",
        "type": "switch",
        "switch": {
            "Off": -1,
            "Auto": 0,
            "Highest": 1,
            "High": 2,
            "Middle": 3,
            "Low": 4,
            "Lowest": 5
        }
    },
    "swingh": {
        "active": "Off",
        "type": "switch",
        "switch": {
            "Off": -1,
            "Auto": 0,
            "LeftMax": 1,
            "Left": 2,
            "Middle": 3,
            "Right": 4,
            "RightMax": 5,
            "Wide": 6
        }
    },
    "light": {
        "active": 1,
        "type": "bool",
        "bool": 0,
    },
    "beep": {
        "active": 1,
        "type": "bool",
        "bool": 0,
    },
    "econo": {
        "active": 1,
        "type": "bool",
        "bool": 0,
    },
    "filter": {
        "active": 1,
        "type": "bool",
        "bool": 0,
    },
    "turbo": {
        "active": 0,
        "type": "bool",
        "bool": 0,
    },
    "quiet": {
        "active": 0,
        "type": "bool",
        "bool": 0,
    },
    "sleep": { //X
        "active": -1,
        "type": "range-int",
        "range-int": [-1, 100] //TODO: enter the real value
    },
    "clean": {
        "active": 1,
        "type": "bool",
        "bool": 0,
    },
    "clock": { //X
        "active": -1,
        "type": "range-int",
        "range-int": [-1, 100] //TODO: enter the real value
    },
    "power": {
        "active": 1,
        "type": "bool",
        "bool": 0,
    },
}

icons = {
    "protocol": "",
    "model": "",
    "mode": "local_fire_department",
    "celsius": "circle",
    "degrees": "device_thermostat",
    "fanspeed": "air",
    "swingv": "swap_horiz",
    "swingh": "swap_vert",
    "light": "light_mode",
    "beep": "volume_off",
    "econo": "spa",
    "filter": "grain",
    "turbo": "bolt",
    "quiet": "volume_down",
    "sleep": "hotel",
    "clean": "sanitizer",
    "clock": "update",
    "power": "power_settings_new",
}

function sendData() {
    var http = new XMLHttpRequest();
    let urlEncodedDataPairs = [], name;
    for (name in ACproperty) {
        urlEncodedDataPairs.push(encodeURIComponent(name) + '=' + encodeURIComponent(ACproperty[name].active));
    }
    var url = '/irSend?' + urlEncodedDataPairs.toString().replaceAll(',', '&');
    http.open('POST', url, true);
    http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    http.onreadystatechange = function () {//Call a function when the state changes.
        if (http.readyState == 4 && http.status == 200) {
            //alert(http.responseText); // TODO: replace with toast ?-> https://www.w3schools.com/howto/howto_js_snackbar.asp
        }
    }
    http.send();
}



// on click -- update database , send command (maybe update esp - the send will do it)
function boolButton(key, value) {
    var card = document.createElement("div")
    card.className = "card"
    card.id = key

    var i = document.createElement("i")
    i.className = "material-icons card-icon"
    i.textContent = icons[key]

    var span = document.createElement("span")
    span.className = "card-title"
    span.textContent = key

    card.appendChild(i)
    card.appendChild(span)
    document.getElementById("card-grid").appendChild(card).addEventListener("click", clicked)

    if (ACproperty[key].active == 0) {
        i.style.color = "red"
    } else {
        i.style.color = "green"
    }
}

function switcher(key, value) { // TODO: join with boolButton
    var card = document.createElement("div")
    card.className = "card"
    card.id = key

    var i = document.createElement("i")
    i.className = "material-icons card-icon"
    i.textContent = icons[key]

    var span = document.createElement("span")
    span.className = "card-title"
    span.textContent = key

    card.appendChild(i)
    card.appendChild(span)
    document.getElementById("card-grid").appendChild(card).addEventListener("click", clicked)
}

function range(key, value, type) {
    var card = document.createElement("div")
    card.className = "card-slider card"

    var span = document.createElement("span")
    span.textContent = key

    var number = document.createElement("span")
    number.textContent = value.active
    number.className = "slider-number"

    var slider = document.createElement("input")
    slider.className = "slider"
    slider.type = "range"
    slider.id = key
    slider.min = value[type][0]
    slider.max = value[type][1]
    slider.value = ACproperty[key].active
    slider.step = type == "range-int" ? 1 : 0.1
    slider.setAttribute("onchange", "updateTextInput(this)");

    card.appendChild(span)
    card.appendChild(number)
    card.appendChild(slider)
    document.getElementById("card-grid2").appendChild(card)
}

function clicked() {
    const id = this.id
    switch (ACproperty[id].type) {
        case "bool":
            ACproperty[id].active = 1 - ACproperty[id].active
            if (ACproperty[id].active == 0) {
                this.getElementsByClassName("card-icon")[0].style.color = "red"
            } else {
                this.getElementsByClassName("card-icon")[0].style.color = "green"
            }
            break;
        case "switch":
            let keyArray = Object.keys(ACproperty[id].switch)
            let activePos = keyArray.findIndex((e) => e == ACproperty[id].active)
            if (activePos == keyArray.length - 1) {
                ACproperty[id].active = keyArray[0]
            } else {
                ACproperty[id].active = keyArray[activePos + 1]
            }
            break;

        default:
            console.log("TYPE ERROR: unaccessible code", ACproperty[id].type)
            break;
    }

    sendData()
}

function updateTextInput(element) {
    element.parentElement.childNodes[1].textContent = element.value
    ACproperty[element.id].active = element.value
    sendData()
}

for (const [key, value] of Object.entries(ACproperty)) {
    switch (value.type) {
        case "bool":
            boolButton(key, value)
            break;
        case "switch":
            switcher(key, value)
            break;
        case "range-int":
            range(key, value, value.type)
            break;
        case "range-float":
            range(key, value, value.type)
            break;

        default:
            console.log("DB ERROR: unaccessible code", value)
            break;
    }
}
)=====";

