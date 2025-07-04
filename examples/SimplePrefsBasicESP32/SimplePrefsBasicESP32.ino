#include <SimplePrefsPlus.h>

SimplePrefsPlus prefs("config");

void setup() {
  Serial.begin(115200);
  delay(1000);

  if (!prefs.loadKey()) {
    Serial.println("AES key not found or invalid. Setup required.");
    while (true); // Stop here, simulate blocking setup screen
  }

  prefs.begin();
  prefs.putString("username", "souvik");
  prefs.putInt("userid", 42);
  prefs.end();

  prefs.begin();
  String username = prefs.getString("username", "none");
  int userid = prefs.getInt("userid", -1);
  prefs.end();

  Serial.println("Read back:");
  Serial.println("username = " + username);
  Serial.println("userid = " + String(userid));
}

void loop() {
  // Nothing here
}
