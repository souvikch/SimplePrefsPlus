#pragma once
#include "storage/ConfigStorage.h"
#include "crypto/TinyAESWrapper.h"

class SimplePrefsPlus {
public:
    SimplePrefsPlus(ConfigStorage* s) : storage(s) {}
    bool begin();
    bool loadKey();
    bool storeKeyFromString(String key);
    bool isKeyValid();
    bool write(const char* key, const String& val);
    String read(const char* key);
    void reset();

private:
    ConfigStorage* storage;
    TinyAESWrapper aes;
    bool keyValid = false;
};