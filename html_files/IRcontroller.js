// TODO:
// - make the slider integrated to the rest (2 colum of button 1 for slider)
// - hide unwanted buttons (add hide to db?)
// - DB check the real values
// - make sure that the icons in bool are ok

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
    if (icons[key].length === 1) {
        i.textContent = icons[key][0]
        if (ACproperty[key].active == 0) {
            i.style.color = "red"
        } else {
            i.style.color = "green"
        }
    }
    else
        i.textContent = icons[key][ACproperty[key].active]


    var span = document.createElement("span")
    span.className = "card-title"
    span.textContent = key

    card.appendChild(i)
    card.appendChild(span)
    document.getElementById("card-grid").appendChild(card).addEventListener("click", clicked)


}

function getPosInDictionary(active, dic) {
    let index = 0
    for ([key, val] of Object.entries(dic)) {
        if (key == active) break;
        index++
    }
    console.log(index)
    return index
}

function switcher(key, value) { // TODO: join with boolButton
    var card = document.createElement("div")
    card.className = "card"
    card.id = key

    var i = document.createElement("i")
    i.className = "material-icons card-icon"

    let index = getPosInDictionary(ACproperty[key]["active"], ACproperty[key]['switch'])

    i.textContent = icons[key][index]

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
    slider.addEventListener("change", updateTextInput)
    slider.addEventListener("input", updateTextInput);

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
            if (icons[id].length === 1)
                if (ACproperty[id].active == 0) {
                    this.getElementsByClassName("card-icon")[0].style.color = "red"
                } else {
                    this.getElementsByClassName("card-icon")[0].style.color = "green"
                }
            else {
                // update icon
                this.firstChild.textContent = icons[id][ACproperty[id].active]
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
            this.firstChild.textContent = icons[id][index]
            break;

        default:
            console.log("TYPE ERROR: unaccessible code", ACproperty[id].type)
            break;
    }

    sendData()
}

function updateTextInput(obj) {
    let element = obj['srcElement']
    element.parentElement.childNodes[1].textContent = element.value
    ACproperty[element.id].active = element.value
    if (obj["type"] !== 'input') {
        sendData()
    }
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

//   to remove sw copy to cmd:
/*
navigator.serviceWorker.getRegistrations().then(function(registrations) {
     for(let registration of registrations) {
      registration.unregister()
    } })
*/