// ������� 9
// ����� ������������ ������� � ������������ ��������� ������
// ����: ������������� ������� �[N,M], ���������� ������ ����������� �����.
// ������������� ������ ������� � ������� ���������� ���� ������� �����
// �����. ���������� ����� ������� ����� ������ �������� ��� �������.
// �����������, �������� �� ����� �������, �������� ��� �������"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

// ������� ��� ��������, �������� �� ����� �������
bool isPrime(int num)
{
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// ������� ��� ���������� ����� ������� ����� � ������
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

// ������� ��� ���������� ����� ������� �� ����� ������� �����
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
    cout << "������� ������� ������� (N M): ";
    cin >> N >> M;

    // ������������ ��������� ������ ��� �������
    int** A = new int*[N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[M];
    }

    srand(static_cast<unsigned int>(time(0)));

    // ���������� ������� ������������ ������� (1-50)
    cout << "\n�������� �������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = rand() % 50 + 1;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // ���������� ����� �� ����� ������� �����
    sortMatrix(A, N, M);

    // ����� ��������������� �������
    cout << "\n��������������� �������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // ������������ ������
    for (int i = 0; i < N; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
