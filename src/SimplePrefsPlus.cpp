#include "SimplePrefsPlus.h"

bool SimplePrefsPlus::begin() {
    return storage->begin();
}

bool SimplePrefsPlus::loadKey() {
    uint8_t key[16];
    size_t len = 0;
    if (!storage->read("aeskey", key, sizeof(key), len) || len != 16) return false;
    aes.setKey(key);
    keyValid = true;
    return true;
}

bool SimplePrefsPlus::storeKeyFromString(String hexKey) {
    if (hexKey.length() != 32) return false;
    uint8_t key[16];
    for (int i = 0; i < 16; i++)
        key[i] = strtoul(hexKey.substring(i * 2, i * 2 + 2).c_str(), nullptr, 16);
    if (!storage->write("aeskey", key, 16)) return false;
    aes.setKey(key);
    keyValid = true;
    return true;
}

bool SimplePrefsPlus::isKeyValid() {
    return keyValid;
}

bool SimplePrefsPlus::write(const char* key, const String& val) {
    if (!keyValid) return false;
    String enc = aes.encrypt(val);
    return storage->write(key, (uint8_t*)enc.c_str(), enc.length());
}

String SimplePrefsPlus::read(const char* key) {
    if (!keyValid) return "";
    uint8_t buf[128];
    size_t len = 0;
    if (!storage->read(key, buf, sizeof(buf), len)) return "";
    return aes.decrypt((char*)buf, len);
}

void SimplePrefsPlus::reset() {
    storage->erase("aeskey");
}