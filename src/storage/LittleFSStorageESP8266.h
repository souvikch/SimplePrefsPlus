#pragma once
#include "ConfigStorage.h"
#include <LittleFS.h>

class LittleFSStorageESP8266 : public ConfigStorage {
public:
    LittleFSStorageESP8266(const char* fn) : filename(fn) {}
    bool begin() override { return LittleFS.begin(); }
    bool write(const char* key, const uint8_t* data, size_t len) override;
    bool read(const char* key, uint8_t* buf, size_t maxLen, size_t& outLen) override;
    bool erase(const char*) override;

private:
    const char* filename;
};