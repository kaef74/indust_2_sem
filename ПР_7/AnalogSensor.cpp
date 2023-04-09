#include "AnalogSensor.h"

AnalogSensor::AnalogSensor(double thresholdValue) {
    threshold = thresholdValue;
    value = 0.0;
}

void AnalogSensor::updateValue(double newValue) {
    value = newValue;
}

bool AnalogSensor::isTriggered() {
    return value >= threshold;
}
