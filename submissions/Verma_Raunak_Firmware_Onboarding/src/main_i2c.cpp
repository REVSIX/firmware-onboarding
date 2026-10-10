#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"

void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMEI2CInterfaceInstance::instance().begin()) {
        Serial.println("BME280 Sensor Disconnected!");
        while (true) {} // Prevent Loop from running
    }
}

void loop() {
    float temperature = BMEI2CInterfaceInstance::instance().readTemperature();
    LEDControllerInstance::instance().update(temperature, millis());
    digitalWrite(LED_BUILTIN,LEDControllerInstance::instance().isOn() ? HIGH: LOW);
}
