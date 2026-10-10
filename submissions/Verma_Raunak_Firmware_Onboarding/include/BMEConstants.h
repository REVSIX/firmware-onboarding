#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t i2cPrimaryAddress = 0x77;
    constexpr uint8_t i2cAlternateAddress = 0x76;
    constexpr uint8_t spiChipSelectPin = 10;
    constexpr float coolTemperatureC = 15.0f;
    constexpr float warmTemperatureC = 35.0f;
    constexpr uint32_t slowBlinkIntervalMs = 1000;
    constexpr uint32_t fastBlinkIntervalMs = 100;
}
