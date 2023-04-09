#include <iostream>
#include "AnalogSensor.h"
#include "EquationType1.h"
#include "EquationType2.h"

int main() {
    AnalogSensor sensor(2.5);
    sensor.updateValue(3.0);
    if (sensor.isTriggered()) {
        std::cout << "Datchik srabotal!" << std::endl;
    }

    EquationType1 eq1;
    eq1.show();
    eq1.Get_answer();

    EquationType2 eq2(2.0);
    eq2.show();
    eq2.Get_answer();

    return 0;
}
