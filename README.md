# SimplePrefsPlus

`SimplePrefsPlus` is an easy-to-use, secure, and lightweight preferences storage library for **ESP8266** and **ESP32** microcontrollers. It wraps around `Preferences` (ESP32) or `LittleFS` (ESP8266) and adds **AES-128 encryption**, automatic key setup, and optional Web UI for configuration.

---

## ✨ Features

- 🔐 AES-128 CBC encryption of stored key-value pairs.
- 🔄 Automatically enters setup mode if no key or invalid key is found.
- 📦 Compact and portable with minimal RAM/Flash usage.
- 🧠 Uniform API for ESP8266 and ESP32.
- 🌐 Optional Web UI interface for initial key provisioning.
- ✅ Works with strings, ints, floats, bools, etc.
- 💾 Uses Preferences on ESP32 and LittleFS on ESP8266.

---

## 📦 Installation

- Place the library folder in your Arduino `libraries/` directory.
- Ensure you have the latest ESP8266/ESP32 board support installed.

---

## 🔧 Basic Usage

```cpp
#include <SimplePrefsPlus.h>

SimplePrefsPlus prefs("config");

void setup() {
  Serial.begin(115200);
  
  if (!prefs.loadKey()) {
    Serial.println("No valid key found. Setup required.");
    while (true); // Block here for setup
  }

  prefs.begin();
  prefs.putString("ssid", "MyWiFi");
  prefs.putInt("boots", 5);
  prefs.end();

  prefs.begin();
  String ssid = prefs.getString("ssid", "none");
  int boots = prefs.getInt("boots", -1);
  prefs.end();
}
