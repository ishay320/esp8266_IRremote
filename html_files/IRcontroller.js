// TODO:
// - fix the sending with the new DB
// - make the slider integrated to the rest (2 colum of button 1 for slider)
// - hide unwanted buttons (add hide to db?)
// - make the switches work with more icons (add array to icons arr?)
// - DB check the real values


// ACproperty = {
//     "protocol": 18,
//     "model": 1,
//     "mode": 0,
//     "celsius": 1,
//     "degrees": 23,
//     "fanspeed": 0,
//     "swingv": -1,
//     "swingh": -1,
//     "light": 1,
//     "beep": 1,
//     "econo": 1,
//     "filter": 1,
//     "turbo": 0,
//     "quiet": 0,
//     "sleep": -1,
//     "clean": 1,
//     "clock": -1,
//     "power": 1
// }

// function?
var ACproperty = {
    "protocol": {//X
        "active": 18,
        "range-int": [1, 100] //TODO: enter the real value
    },
    "model": { //X
        "active": 1,
        "range-int": [1, 100] //TODO: enter the real value
    },
    "mode": {
        "active": "off",
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
        "bool": 0,
    },
    "degrees": { //X
        "active": 26,
        "range-float": [16, 40]
    },
    "fanspeed": {
        "active": "Auto",
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
        "active": "off",
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
        "active": "off",
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
        "bool": 0,
    },
    "beep": {
        "active": 1,
        "bool": 0,
    },
    "econo": {
        "active": 1,
        "bool": 0,
    },
    "filter": {
        "active": 1,
        "bool": 0,
    },
    "turbo": {
        "active": 0,
        "bool": 0,
    },
    "quiet": {
        "active": 0,
        "bool": 0,
    },
    "sleep": { //X
        "active": -1,
        "range-int": [1, 100] //TODO: enter the real value
    },
    "clean": {
        "active": 1,
        "bool": 0,
    },
    "clock": { //X
        "active": -1,
        "range-int": [1, 100] //TODO: enter the real value
    },
    "power": {
        "active": 1,
        "bool": 0,
    },
}

icons = {
    "protocol": "",
    "model": "",
    "mode": "local_fire_department",
    "celsius": "",
    "degrees": "",
    "fanspeed": "air",
    "swingv": "",
    "swingh": "",
    "light": "nightlight",
    "beep": "volume_off",
    "econo": "",
    "filter": "",
    "turbo": "",
    "quiet": "",
    "sleep": "",
    "clean": "",
    "clock": "update",
    "power": "power",
}

function click(evt) {
    // alert(evt.currentTarget["id"]);
    if (ACproperty[evt.currentTarget["id"]] == 1) {
        ACproperty[evt.currentTarget["id"]] = 0
        evt.currentTarget.getElementsByClassName("card-icon")[0].style.color = "red"
    } else {
        ACproperty[evt.currentTarget["id"]] = 1
        evt.currentTarget.getElementsByClassName("card-icon")[0].style.color = "green"
    }
    send()

}
function send() {
    var http = new XMLHttpRequest();
    var url = '/irSend';
    http.open('POST', url, true);
    http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    http.onreadystatechange = function () {//Call a function when the state changes.
        if (http.readyState == 4 && http.status == 200) {
            alert(http.responseText); // TODO: replace with toast ?-> https://www.w3schools.com/howto/howto_js_snackbar.asp
        }
    }
    let urlEncodedDataPairs = [], name;
    for (name in ACproperty) {
        urlEncodedDataPairs.push(encodeURIComponent(name) + '=' + encodeURIComponent(ACproperty[name]));
    }
    http.send(urlEncodedDataPairs.toString());
    // JSON.stringify(ACproperty)

}


// TODO: send as: /irSend?protocol=18&model=1&mode=0&celsius=1&degrees=23&fanspeed=0&swingv=-1&swingh=-1&light=1&beep=1&econo=1&filter=1&turbo=0&quiet=0&sleep=-1&clean=1&clock=-1&power=1
// or as json - but change the esp code <- better
function httpGet() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", "/irSend", false); // false for synchronous request
    // xmlhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
    xmlHttp.send(ACproperty);
    return xmlHttp.responseText;
}
const collection = document.getElementsByClassName("card");
[].forEach.call(collection, function (element) {
    element.addEventListener("click", click)
});




// on click -- update database , send command (maybe update esp - the send will do it)
function bool(key, value) {
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
    document.getElementById("card-grid").appendChild(card).addEventListener("click", click)

}
function switcher(key, value) { // TODO: make it better and working
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
    document.getElementById("card-grid").appendChild(card).addEventListener("click", click)
}

function range(key, value, type) {
    var card = document.createElement("div")
    card.className = "card-slider card"
    card.id = key

    var span = document.createElement("span")
    span.textContent = key

    var number = document.createElement("span")
    number.textContent = value.active
    number.className = "slider-number"

    var slider = document.createElement("input")
    slider.className = "slider"
    slider.type = "range"
    slider.id = "myRange"
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

function updateTextInput(element) {
    element.parentElement.childNodes[1].textContent = element.value
}

for (const [key, value] of Object.entries(ACproperty)) {
    tmpKey = Object.keys(value)
    switch (tmpKey[1]) {
        case "bool":
            bool(key, value)
            break;
        case "switch":
            switcher(key, value)
            break;
        case "range-int":
            range(key, value, tmpKey[1])
            break;
        case "range-float":
            range(key, value, tmpKey[1])
            break;

        default:
            console.log("DB ERROR: unaccessible code")
            break;
    }
}
