#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

class AnalogSensor {
private:
    double threshold;
    double value;

public:
    AnalogSensor(double thresholdValue);
    void updateValue(double newValue);
    bool isTriggered();
};

#endif /* ANALOG_SENSOR_H */
