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
    <link rel="manifest" href="manifest.json">
    <title>IR controller</title>
</head>

<body>
    <h1 class="title">IR controller</h1>
    <div class="body">
        <div class="card-grid" id="card-grid">
            <!-- <div class="card" id="time">
                <input class="card-input" type="time" name="time" id="input-time">
                <span class="card-title">clock</span>
            </div> -->
        </div>
    </div>
    <div id="toast-massage"></div>
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

    <template id="card-template">
        <div class="card" id="title">
            <i class="material-icons card-icon">icon_name</i>
            <span class="card-title">title</span>
        </div>
    </template>

    <template id="card-slider-template">
        <div class="card-slider card">
            <span>title</span>
            <input class="slider" type="range" id="title" min="1" max="100" step="1">
            <span class="slider-number">0</span>
        </div>
    </template>

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
    <nav class="nav-button">
        <form class="card" onclick="window.location.href='/'">
            <i class="material-icons card-icon">home</i>
            <span class="card-title">Home</span>
        </form>
    </nav>

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

    <form action="/html_IRController.html">
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
    user-select: none;
    -moz-user-select: none;
    -khtml-user-select: none;
    -webkit-user-select: none;
    -o-user-select: none;   
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
    align-items: center;
}
.card-grid{
    display: grid;
    grid-template-columns: auto auto;
    font-size: 2em;
    grid-gap: 10px;
}
.card {
    display: flex;
    justify-content: center;
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
    font-size: 1em;
    top: 0.15em;
    margin: 0 0.2em 0 0;
}
.card-slider {
    display: flex;
    align-items: center;
    flex-direction: column;
    transition-duration: 0.4s;
    font-size: 0.6em;
}
.card-slider:hover {
    background-color: rgb(110, 110, 110);
    text-shadow: 5px 5px 6px rgb(63, 62, 62);
}
.empty{
    height:5px;
    background-color: gray;
    border-radius: 10px;
}
.slider-number{
    margin: 0 0 -0.6em 0;
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
}
input[type=time] {
    border: none;
    color: white;
    font-size: 1em;
    background-color: transparent;
}

/* The toast */
#toast-massage {
    visibility: hidden;
    min-width: 250px;
    margin-left: -125px;
    background-color: #333;
    color: #fff;
    text-align: center;
    border-radius: 2px;
    padding: 16px;
    position: fixed;
    z-index: 1;
    left: 50%;
    bottom: 30px;
  }

  #toast-massage.show {
    visibility: visible;
    animation: fadeIn 0.5s, fadeout 0.5s 2.5s;
  }

  @keyframes fadeIn {
    from {bottom: 0; opacity: 0;}
    to {bottom: 30px; opacity: 1;}
  }

  @keyframes fadeout {
    from {bottom: 30px; opacity: 1;}
    to {bottom: 0; opacity: 0;}
  }
  .nav-button{
    font-size: 2em;
    display: flex;
  })=====";

const char IRcontroller[] = R"=====(// TODO:
// - DB check the real values
// - make sure that the icons in bool are ok
// - check what values the clock need
// - add user custom ordering (edit)
// - clean up the button making:
//  - fix bottom int in range

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
    "protocol": [""],
    "model": [""],
    "mode": ["highlight_off", "font_download", "ac_unit", "wb_sunny", "water_drop", "air"],
    "celsius": ["circle"],
    "degrees": ["device_thermostat"],
    "fanspeed": ["filter_none", "filter_1", "filter_2", "filter_3", "filter_4", "filter_5"],
    "swingv": ["horizontal_rule", "swap_horiz", "filter_1", "filter_2", "filter_3", "filter_4", "filter_5"],
    "swingh": ["more_vert", "swap_vert", "filter_1", "filter_2", "filter_3", "filter_4", "filter_5"],
    "light": ["light_mode", "mode_night"],
    "beep": ["volume_off", "volume_up"],
    "econo": ["spa"],
    "filter": ["blur_on", "blur_off"],
    "turbo": ["flash_on", "flash_off"],
    "quiet": ["volume_down", "volume_up"],
    "sleep": ["hotel"],
    "clean": ["sanitizer"],
    "clock": ["update"],
    "power": ["power_settings_new"],
}

var setting = {
    "order": {
        "power": 2,
        "degrees": 2,
        "mode": 1,
        "fanspeed": 1,
        "empty1": 2,
        "swingv": 1,
        "swingh": 1,
        "light": 1,
        "beep": 1,
        "econo": 1,
        "filter": 1,
        "turbo": 1,
        "quiet": 1,
        "clean": 1,
        "empty2": 1,
        "sleep": 1,
        "clock": 1,
        "protocol": 2,
        "celsius": 0,
        "model": 0,
    }
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
    http.onreadystatechange = function () {
        if (http.readyState == 4 && http.status == 200) {
            if (JSON.parse(http.response)['OK'] == 1) {
                toast('command sended successfully')
            } else {
                toast('command failed sending')
            }
        }
    }
    http.send();
}

function addButton(name, type, size) {
    var card = document.querySelector("#card-template").content.cloneNode(true)
    var div = card.firstElementChild;
    div.id = name
    if (size > 1) {
        div.style = "grid-column: 1 / " + (size + 1) + ";"
    } else if (size == 0 | size == undefined) {
        return
    }

    var i = card.querySelector("i")
    switch (type) {
        case "bool":
            if (icons[name].length === 1) {
                i.textContent = icons[name][0]
                if (ACproperty[name].active == 0) {
                    i.style.color = "red"
                } else {
                    i.style.color = "green"
                }
            }
            else
                i.textContent = icons[name][ACproperty[name].active]
            break;
        case "switch":
            let index = getPosInDictionary(ACproperty[name]["active"], ACproperty[name]['switch'])
            i.textContent = icons[name][index]
            break;
        default:
            return
    }

    var span = card.querySelector("span")
    span.textContent = name

    div.addEventListener("click", clicked)
    document.getElementById("card-grid").appendChild(card)
}

function getPosInDictionary(find, dic) {
    let index = 0
    for ([key, _] of Object.entries(dic)) {
        if (key == find) break;
        index++
    }
    return index
}

function range(key, value, type) {
    var card = document.querySelector("#card-slider-template").content.cloneNode(true)
    var div = card.firstElementChild;
    if (setting.order[key] == 2) {
        div.style = "grid-column: 1 / 3;"
    } else if (setting.order[key] == 0) {
        return
    }

    var span = card.querySelectorAll("span")
    span[0].textContent = key
    span[1].textContent = value.active

    var slider = card.querySelector(".slider")
    slider.id = key
    slider.min = value[type][0]
    slider.max = value[type][1]
    slider.value = ACproperty[key].active
    slider.step = type == "range-int" ? 1 : 0.1
    slider.addEventListener("change", updateTextInput)
    slider.addEventListener("input", updateTextInput);

    document.getElementById("card-grid").appendChild(card)
}

function addEmpty(size) {
    var div = document.createElement("empty");
    if (size == 2) {
        div.classList.add("empty")
        div.style = "grid-column: 1 / 3;";
    }
    document.getElementById("card-grid").appendChild(div)
}

function clicked() {
    const id = this.id
    switch (ACproperty[id].type) {
        case "bool":
            ACproperty[id].active = 1 - ACproperty[id].active
            if (icons[id].length === 1)
                if (ACproperty[id].active == 0) {
                    this.getElementsByClassName("card-icon")[0].style.color = "red"
                } else {
                    this.getElementsByClassName("card-icon")[0].style.color = "green"
                }
            else {
                // update icon
                this.firstElementChild.textContent = icons[id][ACproperty[id].active]
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
            // update icon
            let index = getPosInDictionary(ACproperty[id]["active"], ACproperty[id]['switch'])
            this.firstElementChild.textContent = icons[id][index]
            break;

        default:
            console.log("TYPE ERROR: unaccessible code", ACproperty[id].type)
            break;
    }

    sendData()
}

function updateTextInput(obj) {
    let element = obj['srcElement']
    element.parentElement.querySelector(".slider-number").textContent = element.value
    ACproperty[element.id].active = element.value
    if (obj["type"] !== 'input') {
        sendData()
    }
}

for (const [key, size] of Object.entries(setting.order)) {
    if (key.includes("empty")) {
        addEmpty(size)
        continue;
    }
    var value = ACproperty[key]
    switch (value.type) {
        case "bool":
        case "switch":
            addButton(key, value.type, setting.order[key])
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

function toast(text) {
    var t = document.getElementById("toast-massage");
    t.className = "show";
    t.textContent = text
    //TODO: add var timeout (in css)
    setTimeout(function () { t.className = t.className.replace("show", ""); }, 3 * 1000);
}

if ('serviceWorker' in navigator) {
    navigator.serviceWorker
        .register('sw.js')
        .then(() => { console.log('Service Worker Registered'); });
}

//   to remove sw copy to cmd:
/*
navigator.serviceWorker.getRegistrations().then(function(registrations) {
     for(let registration of registrations) {
      registration.unregister()
    } })
*/)=====";

const char sw[] = R"=====(self.addEventListener('install', (e) => {
    e.waitUntil(
      caches.open('fox-store').then((cache) => cache.addAll([
        'html_IRController.html',
        'IRcontroller.js',
        'style.css',
      ])),
    );
  });
  
  self.addEventListener('fetch', (e) => {
    console.log(e.request.url);
    e.respondWith(
      caches.match(e.request).then((response) => response || fetch(e.request)),
    );
  });)=====";

const char manifest[] = R"=====({
    "background_color": "blue",
    "description": "control AC",
    "display": "standalone",
    "icons": [
      {
        "src": "https://image.flaticon.com/icons/png/512/114/114735.png",
        "sizes": "512x512",
        "type": "image/png"
      }
    ],
    "name": "AC controller",
    "short_name": "AC",
    "start_url": "html_IRController.html"
  })=====";

