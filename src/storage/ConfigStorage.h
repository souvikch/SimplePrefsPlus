#pragma once
class ConfigStorage {
public:
    virtual bool begin() = 0;
    virtual bool write(const char*, const uint8_t*, size_t) = 0;
    virtual bool read(const char*, uint8_t*, size_t, size_t& outLen) = 0;
    virtual bool erase(const char*) = 0;
};