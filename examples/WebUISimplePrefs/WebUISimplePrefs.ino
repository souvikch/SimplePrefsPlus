#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SimplePrefsPlus.h>

SimplePrefsPlus prefs("config");
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  prefs.begin();
  server.begin();
}

void loop() {
  server.handleClient();#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SimplePrefsPlus.h>

const char* ssid = "YourSSID";
const char* password = "YourPassword";

ESP8266WebServer server(80);
SimplePrefsPlus prefs("config");

// HTML for basic UI
const char* htmlForm = R"rawliteral(
<!DOCTYPE html>
<html>
<head><title>SimplePrefsPlus Config</title></head>
<body>
  <h1>Config</h1>
  <form action="/store" method="post">
    Key: <input type="text" name="key"><br>
    Value: <input type="text" name="value"><br>
    <input type="submit" value="Store">
  </form>
  <br>
  <form action="/read" method="get">
    Key: <input type="text" name="key"><br>
    <input type="submit" value="Read">
  </form>
  <br>
  <form action="/reset" method="post">
    <input type="submit" value="Reset All">
  </form>
</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", htmlForm);
}

void handleStore() {
  if (server.hasArg("key") && server.hasArg("value")) {
    String key = server.arg("key");
    String value = server.arg("value");

    prefs.begin();
    prefs.putString(key.c_str(), value);
    prefs.end();

    server.send(200, "text/plain", "Stored: " + key + " = " + value);
  } else {
    server.send(400, "text/plain", "Missing key or value");
  }
}

void handleRead() {
  if (server.hasArg("key")) {
    String key = server.arg("key");

    prefs.begin();
    String value = prefs.getString(key.c_str(), "[not found]");
    prefs.end();

    server.send(200, "text/plain", key + " = " + value);
  } else {
    server.send(400, "text/plain", "Missing key");
  }
}

void handleReset() {
  prefs.resetKey();  // Erases encryption key
  server.send(200, "text/plain", "Key reset. Reboot device.");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  prefs.begin();  // will trigger setup page if no key

  server.on("/", handleRoot);
  server.on("/store", HTTP_POST, handleStore);
  server.on("/read", HTTP_GET, handleRead);
  server.on("/reset", HTTP_POST, handleReset);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

}
