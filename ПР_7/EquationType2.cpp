#include <iostream>
#include "EquationType2.h"

EquationType2::EquationType2(double a1) {
    A = a1;
}

void EquationType2::Get_answer() {
    std::cout << "Resheniyem yavlyaetsya x = 0" << std::endl;
}

void EquationType2::show() {
    std::cout << A << "x^2 = 0" << std::endl;
}
