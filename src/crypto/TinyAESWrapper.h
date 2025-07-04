#pragma once
#include <Arduino.h>
extern "C" {
#include "crypto/tiny_aes.h"
}

class TinyAESWrapper {
public:
    void setKey(const uint8_t* k) { memcpy(key, k, 16); }
    String encrypt(String plain);
    String decrypt(const char* enc, size_t len);

private:
    uint8_t key[16];
};