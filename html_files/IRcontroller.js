ACproperty = {
    "protocol": 18,
    "model": 1,
    "mode": 0,
    "celsius": 1,
    "degrees": 23,
    "fanspeed": 0,
    "swingv": -1,
    "swingh": -1,
    "light": 1,
    "beep": 1,
    "econo": 1,
    "filter": 1,
    "turbo": 0,
    "quiet": 0,
    "sleep": -1,
    "clean": 1,
    "clock": -1,
    "power": 1
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
    httpGet()

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

