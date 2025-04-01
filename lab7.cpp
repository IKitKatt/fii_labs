// Задание 9
// Можно использовать функции и динамическое выделение памяти
// Дано: прямоугольная матрица А[N,M], содержащая только натуральные числа.
// Отсортировать строки матрицы в порядке неубывания сумм простых чисел
// строк. Нахождение суммы простых чисел строки оформить как функцию.
// Определение, является ли число простым, оформить как функцию"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int num)
{
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Функция для вычисления суммы простых чисел в строке
int sumOfPrimes(int* row, int M)
{
    int sum = 0;
    for (int j = 0; j < M; j++) {
        if (isPrime(row[j])) {
            sum += row[j];
        }
    }
    return sum;
}

// Функция для сортировки строк матрицы по сумме простых чисел
void sortMatrix(int** A, int N, int M)
{
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (sumOfPrimes(A[j], M) > sumOfPrimes(A[j + 1], M)) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N, M;
    cout << "Введите размеры матрицы (N M): ";
    cin >> N >> M;

    // Динамическое выделение памяти для матрицы
    int** A = new int*[N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[M];
    }

    srand(static_cast<unsigned int>(time(0)));

    // Заполнение матрицы натуральными числами (1-50)
    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = rand() % 50 + 1;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Сортировка строк по сумме простых чисел
    sortMatrix(A, N, M);

    // Вывод отсортированной матрицы
    cout << "\nОтсортированная матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
