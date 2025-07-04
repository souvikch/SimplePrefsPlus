#pragma once
#include "ConfigStorage.h"
#include <Preferences.h>

class PrefsStorageESP32 : public ConfigStorage {
public:
    PrefsStorageESP32(const char* ns) : nsName(ns) {}
    bool begin() override;
    bool write(const char* key, const uint8_t* data, size_t len) override;
    bool read(const char* key, uint8_t* buf, size_t maxLen, size_t& outLen) override;
    bool erase(const char* key) override;

private:
    const char* nsName;
    Preferences prefs;
};