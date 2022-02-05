// TODO:
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