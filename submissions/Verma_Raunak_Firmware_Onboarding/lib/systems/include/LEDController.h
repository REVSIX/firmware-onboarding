#pragma once
#include <stdint.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void update(float temperature, uint32_t nowMs);
    bool isOn() const;
    uint32_t getLEDInterval() const;

private:
    enum class State { Off, On };

    State state_ = State::Off;
    uint32_t lastToggleMs_ = 0;
    uint32_t intervalMs_ = BMEConstants::slowBlinkIntervalMs;
};

using LEDControllerInstance = etl::singleton<LEDController>;
