# SimplePrefsPlus

**SimplePrefsPlus** is a lightweight Arduino-compatible library for ESP8266 and ESP32 that provides encrypted key-value configuration storage using AES-128. It supports both Preferences (ESP32) and LittleFS (ESP8266) backends and can optionally expose a Web UI for first-time setup.

---

## ✨ Features

- 🔐 AES-128 encryption using TinyAES
- ⚙️ Stores config in Preferences (ESP32) or LittleFS (ESP8266)
- 🌐 Optional Web UI to enter and store encryption key
- 🧠 Auto-reset and reconfigure on key decode failure
- 🧩 Easy to extend for new data types or storage
- 🧵 Lightweight and non-blocking for most operations

---

## 📦 Installation

Copy the library to your Arduino `libraries/` folder or use PlatformIO.

---

## 📚 Basic Usage

### ESP8266

```cpp
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

  prefs.write("ssid", "MyWiFi");
  Serial.println(prefs.read("ssid"));
}
