#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //����������
    float m, b, t, c, z;

    //���� ���������� � ����������
    cout << "������� ����� M: ";
    cin >> m;
    cout << "������� ����� C: ";
    cin >> c;
    cout << "������� ����� T: ";
    cin >> t;
    cout << "������� ����� B: ";
    cin >> b;

    //�������
    z = sqrt(m) * cos(pow(b, 3.0) + sin(t - 1.0)) + fabs(c);

    //����� ����������
    cout << "\n���������: " << z;

    return 0;
}