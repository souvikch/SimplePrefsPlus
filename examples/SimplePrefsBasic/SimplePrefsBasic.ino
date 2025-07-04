#include <Arduino.h>
#include <SimplePrefsPlus.h>

#ifdef ESP32
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

// Use the namespace for encrypted preferences
SimplePrefsPlus prefs("config");

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n=== SimplePrefsPlus Basic Example ===");

  // Load the stored encryption key
  if (!prefs.loadKey()) {
    Serial.println("⚠️  No valid key found or decryption failed.");
    Serial.println("➡️  Please enter new AES key (16 chars):");
    prefs.setupKeyFromSerial();  // blocking setup
  }

  // Begin preference session
  prefs.begin();

  // Store encrypted values
  prefs.putString("username", "souvik");
  prefs.putInt("userage", 30);

  // Retrieve stored values
  String username = prefs.getString("username", "unknown");
  int age = prefs.getInt("userage", -1);

  Serial.println("Username: " + username);
  Serial.print("User Age: ");
  Serial.println(age);

  prefs.end();
}

void loop() {
  // No recurring logic needed
}
