# SimplePrefsPlus

**Encrypted key-value configuration storage for ESP8266 and ESP32.**

---

## 🚀 Features

- 🔐 AES-128 CBC encryption for secure storage
- 📦 Stores config values (strings, ints, floats) with auto-type detection
- 🧠 Supports ESP32 `Preferences` or ESP8266 `LittleFS` backend
- 🔄 Automatically enters setup mode if key is missing or corrupted
- 🌐 Web UI for remote config (optional)
- 🧪 Lightweight: optimized for embedded flash + RAM
- ✅ Works with both **ESP32** and **ESP8266**

---

## 🔧 Installation

1. Clone or download this repository
2. Open Arduino IDE
3. Select **Sketch > Include Library > Add .ZIP Library...**
4. Choose this repo's root folder or ZIP

---

## 🔰 Basic Usage

```cpp
#include <SimplePrefsPlus.h>

SimplePrefsPlus prefs("config");

void setup() {
  Serial.begin(115200);
  if (!prefs.loadKey()) {
    prefs.setupKeyFromSerial(); // prompt user to enter 16-char key
  }
  prefs.begin();

  prefs.putString("ssid", "MyWiFi");
  prefs.putInt("port", 8080);

  Serial.println(prefs.getString("ssid"));
  Serial.println(prefs.getInt
