#ifndef RATIONAL_H
#define RATIONAL_H

class rational {
public:
    rational(int a1 = 0, int b1 = 1); // конструктор
    void set(int a1, int b1); // установка значений
    void show() const; // вывод дроби
private:
    int a; // числитель
    int b; // знаменатель
};

#endif