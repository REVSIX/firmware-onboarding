#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    return sensor.begin(BME280_ADDRESS) || sensor.begin(BME280_ADDRESS_ALTERNATE);
}

float BMEI2CInterface::readTemperature()
{
    return sensor.readTemperature();
}

float BMEI2CInterface::readPressure()
{
    return sensor.readPressure();
}

float BMEI2CInterface::readHumidity()
{
    return sensor.readHumidity();
}
