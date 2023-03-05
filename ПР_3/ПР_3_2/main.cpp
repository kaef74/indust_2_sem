#include "rational.h"
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of fractions: ";
    cin >> n;
    rational *fractions = new rational[n]; // создание динамического массива
    for (int i = 0; i < n; i++) {
        int a, b;
        cout << "Enter the numerator and denominator of fraction " << i + 1 << ": ";
        cin >> a >> b;
        fractions[i].set(a, b); // установка значений
    }
    for (int i = 0; i < n; i++) {
        fractions[i].show(); // вывод дроби
    }
    delete[] fractions; // освобождение памяти
    return 0;
}
