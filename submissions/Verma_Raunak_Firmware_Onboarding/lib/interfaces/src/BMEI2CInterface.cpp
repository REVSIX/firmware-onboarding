#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    return sensor.begin(BMEConstants::i2cPrimaryAddress) ||
           sensor.begin(BMEConstants::i2cAlternateAddress);
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
