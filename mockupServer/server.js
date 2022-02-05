const express = require('express')
const app = express()
const port = 3000
/*

server.on("/irSend", handleLedProg); // gets all the data to send to the AC
server.on("/test", handleTest); // check the next AC and show what he done
server.on("/wifiInfo", handleSSIDData); // need to receive SSID and pass

server.on("/temp", handleSendData); // send temp
 */
app.use(
    express.urlencoded({
      extended: true
    })
  )
  
app.get('/', (req, res) => {
    res.sendFile( __dirname.replace("mockupServer","html_files/html_menu.html"));
})

app.get('/html_IRController.html', (req, res) => {
    res.sendFile( __dirname.replace("mockupServer","html_files/html_IRController.html"));
})
app.get('/IRcontroller.js', (req, res) => {
    res.sendFile( __dirname.replace("mockupServer","html_files/IRcontroller.js"));
})

app.get('/wifiLogin', (req, res) => {
    res.sendFile( __dirname.replace("mockupServer","html_files/html_wifiLogin.html"));
})

// PWA  
app.get('/manifest.json', (req, res) => {
    res.sendFile( __dirname.replace("mockupServer","html_files/manifest.json"));
})
app.get('/sw.js', (req, res) => {
    res.sendFile( __dirname.replace("mockupServer","html_files/sw.js"));
})

app.post('/irSend', (req, res) => {
    let url = req.url
    console.log('Got url:', url);
    console.log("parsed: ",url.slice(8).replace(/&/g,' ').split(" "))
    res.json({"OK":1});
})


app.get('/getWireless', (req, res) => {
    // send the data to the user
    res.json({"SSID":["first_ssid","second_ssid"]});
})

app.get('/style.css', (req, res) => {
    // send the style.css file to the user
    res.sendFile( __dirname.replace("mockupServer","html_files/style.css"));
})

app.listen(port, () => {
    console.log(`app listening at http://localhost:${port}`)
})