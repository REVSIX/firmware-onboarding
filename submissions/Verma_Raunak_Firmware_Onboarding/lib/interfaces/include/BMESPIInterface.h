#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMESPIInterface
{
public:

    BMESPIInterface() = default;

    bool begin();
    float readTemperature();
    float readPressure();
    float readHumidity();

private:

    Adafruit_BME280 sensor;

};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;