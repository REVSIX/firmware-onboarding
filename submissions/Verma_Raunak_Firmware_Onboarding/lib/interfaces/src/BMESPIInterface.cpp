#include "BMESPIInterface.h"
bool BMESPIInterface::begin()
{
    return sensor.begin(BME280_ADDRESS) || sensor.begin(BME280_ADDRESS_ALTERNATE);
}

float BMESPIInterface::readTemperature()
{
    return sensor.readTemperature();
}

float BMESPIInterface::readPressure()
{
    return sensor.readPressure();
}

float BMESPIInterface::readHumidity()
{
    return sensor.readHumidity();
}
