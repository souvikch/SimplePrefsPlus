#include <Preferences.h>
#include "SimplePrefsPlus.h"
#include "storage/PrefsStorageESP32.h"

PrefsStorageESP32 storage("config");
SimplePrefsPlus prefs(&storage);

void setup() {
  Serial.begin(115200);
  prefs.begin();
  if (!prefs.loadKey()) {
    prefs.storeKeyFromString("00112233445566778899aabbccddeeff");
  }
  prefs.write("ssid", "myESP32SSID");
  Serial.println(prefs.read("ssid"));
}
void loop() {}