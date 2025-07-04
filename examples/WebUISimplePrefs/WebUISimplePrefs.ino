#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SimplePrefsPlus.h>

const char* ssid = "YourSSID";
const char* password = "YourPassword";

ESP8266WebServer server(80);
SimplePrefsPlus prefs("config");

String htmlHeader = R"rawlit(
<!DOCTYPE html><html><head><meta name="viewport" content="width=device-width, initial-scale=1">
<title>SimplePrefsPlus Config</title></head><body>
<h2>SimplePrefsPlus Web Config</h2>
)rawlit";

String htmlFooter = R"rawlit(
</body></html>
)rawlit";

void handleRoot() {
  String html = htmlHeader;
  html += R"rawlit(
<form action="/store" method="POST">
  AES Key: <input type="text" name="key" maxlength="32"><br><br>
  <input type="submit" value="Store Key">
</form>
<form action="/test" method="POST" style="margin-top:20px;">
  <input type="submit" value="Test Decryption">
</form>
<form action="/reset" method="POST" style="margin-top:20px;">
  <input type="submit" value="Reset Key">
</form>
)rawlit";
  html += htmlFooter;
  server.send(200, "text/html", html);
}

void handleStore() {
  String ke
