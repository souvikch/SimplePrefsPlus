#include <LittleFS.h>
#include "SimplePrefsPlus.h"
#include "storage/LittleFSStorageESP8266.h"

LittleFSStorageESP8266 storage("/config.dat");
SimplePrefsPlus prefs(&storage);

void setup() {
  Serial.begin(115200);
  prefs.begin();
  if (!prefs.loadKey()) {
    prefs.storeKeyFromString("00112233445566778899aabbccddeeff");
  }
  prefs.write("ssid", "mySSID");
  Serial.println(prefs.read("ssid"));
}
void loop() {}