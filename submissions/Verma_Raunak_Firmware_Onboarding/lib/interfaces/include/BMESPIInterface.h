#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMESPIInterface
{
public:

    BMESPIInterface() = default;

    // Code here!

private:

   // Code here!

};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;