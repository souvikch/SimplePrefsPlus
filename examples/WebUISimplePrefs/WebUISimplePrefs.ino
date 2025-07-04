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
  server.handleClient();
}
