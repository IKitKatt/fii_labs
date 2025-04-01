#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Переменные
    float m, b, t, c, z;

    //Ввод переменных с клавиатуры
    cout << "Введите число M: ";
    cin >> m;
    cout << "Введите число C: ";
    cin >> c;
    cout << "Введите число T: ";
    cin >> t;
    cout << "Введите число B: ";
    cin >> b;

    //Формула
    z = sqrt(m) * cos(pow(b, 3.0) + sin(t - 1.0)) + fabs(c);

    //Вывод результата
    cout << "\nРезультат: " << z;

    return 0;
}