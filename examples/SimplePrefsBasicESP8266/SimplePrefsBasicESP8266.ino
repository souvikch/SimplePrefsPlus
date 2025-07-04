#include <SimplePrefsPlus.h>

SimplePrefsPlus prefs("config");

void setup() {
  Serial.begin(115200);
  delay(1000);

  if (!prefs.loadKey()) {
    Serial.println("AES key not found or invalid. Setup required.");
    while (true); // Halt, simulate entering setup mode
  }

  prefs.begin();
  prefs.putString("deviceName", "esp8266_test");
  prefs.putInt("bootCount", 1);
  prefs.end();

  prefs.begin();
  String device = prefs.getString("deviceName", "undefined");
  int boots = prefs.getInt("bootCount", -1);
  prefs.end();

  Serial.println("Read back:");
  Serial.println("deviceName = " + device);
  Serial.println("bootCount = " + String(boots));
}

void loop() {
  // Idle loop
}
