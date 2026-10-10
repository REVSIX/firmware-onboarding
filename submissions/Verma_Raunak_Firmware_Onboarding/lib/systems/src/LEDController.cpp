#include "LEDController.h"

#include <math.h>

void LEDController::update(float temperature, uint32_t nowMs)
{
    if (isnan(temperature)) {
        return;
    }

    if (temperature <= BMEConstants::coolTemperatureC) {
        intervalMs_ = BMEConstants::slowBlinkIntervalMs;
    } else if (temperature >= BMEConstants::warmTemperatureC) {
        intervalMs_ = BMEConstants::fastBlinkIntervalMs;
    } else {
        const float fraction = (temperature - BMEConstants::coolTemperatureC) /
                               (BMEConstants::warmTemperatureC - BMEConstants::coolTemperatureC);
        const float range = static_cast<float>(BMEConstants::slowBlinkIntervalMs -
                                               BMEConstants::fastBlinkIntervalMs);
        intervalMs_ = BMEConstants::slowBlinkIntervalMs -
                      static_cast<uint32_t>(fraction * range);
    }

    if (nowMs - lastToggleMs_ >= intervalMs_) {
        state_ = state_ == State::Off ? State::On : State::Off;
        lastToggleMs_ = nowMs;
    }
}

bool LEDController::isOn() const
{
    return state_ == State::On;
}

uint32_t LEDController::getLEDInterval() const
{
    return intervalMs_;
}
