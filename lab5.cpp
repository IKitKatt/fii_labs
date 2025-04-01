// ������� 7
// ��� ������������� ������ �[N][�]. ������������ ���������� ������
// �[�] �� ������������ ������������� ��������� ��������������� ��������
// ������� �.


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������� �������
    const int N = 5, M = 4;


    int A[N][M];
    int B[M]; // ���������� ������ ��� ������������ ��������

    srand(static_cast<unsigned int>(time(0))); // ������������� ���������� ��������� �����

    // ���������� ������� ���������� ������� � ��������� [-5, 5]
    cout << "\n������� A:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = rand() % 11 - 5; // �������� �� -5 �� 5
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // ������������ ������� B
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
        B[j] = hasPositive ? product : 0; // ���� ��� �������������, ���������� 0
    }

    // ����� ������� B
    cout << "\n������ B:" << endl;
    for (int j = 0; j < M; j++)
    {
        cout << B[j] << " ";
    }
    cout << endl;

    return 0;
}
