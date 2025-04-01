// Задание 7
// Дан целочисленный массив А[N][М]. Сформировать одномерный массив
// В[М] из произведений положительных элементов соответствующих столбцов
// массива А.


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Размеры массива
    const int N = 5, M = 4;


    int A[N][M];
    int B[M]; // Одномерный массив для произведений столбцов

    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    // Заполнение массива случайными числами в диапазоне [-5, 5]
    cout << "\nМатрица A:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = rand() % 11 - 5; // Диапазон от -5 до 5
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Формирование массива B
    for (int j = 0; j < M; j++)
    {
        int product = 1;
        bool hasPositive = false;
        for (int i = 0; i < N; i++)
        {
            if (A[i][j] > 0)
            {
                product *= A[i][j];
                hasPositive = true;
            }
        }
        B[j] = hasPositive ? product : 0; // Если нет положительных, записываем 0
    }

    // Вывод массива B
    cout << "\nМассив B:" << endl;
    for (int j = 0; j < M; j++)
    {
        cout << B[j] << " ";
    }
    cout << endl;

    return 0;
}
