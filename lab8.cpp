// ������� 10
// ��� ������������� ������, ����������� �� ����� 10 �����, � ������ ������
// �� ����� 80 ��������, ������������ ������, �������� �������� �����
// ������ ����. ������� �� ����� �������� ����� � �������������� ������.

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_LINES = 10;
    const int MAX_LENGTH = 80;
    string text[MAX_LINES];
    vector<int> wordLengths;

    // ������ ������
    // � ���� ������� �����: �, ����, ����, ������� ������, ������� � �������.
    // �� ����� ��� ������ � ������� ����� � ������ ������ � ������� ���� � �������.
    // ��� ���� ������ ������ ����, ������ ��� ��� ���� �� ������.
    // �� �������� ��������. ������ ������� ������� ��� �������.
    // � ������ ������� ����, � ��� ������ ��� � �����.

    cout << "������� ����� (�� ����� 10 �����, ������ �� 80 ��������). ������ ������ ��������� ����:" << endl;
    int lineCount = 0;

    // �������� ����� ������ ����� While
    while (lineCount < MAX_LINES)
    {
        string line;
        getline(cin, line);
        if (line.empty()) break;
        if (line.length() > MAX_LENGTH)
        {
            cout << "��������� ������������ ����� ������ (80 ��������), ���������� �����." << endl;
            continue;
        }
        text[lineCount++] = line;
    }

    cout << "\n�������� �����:" << endl;
    for (int i = 0; i < lineCount; i++)
    {
        cout << text[i] << endl;
        stringstream ss(text[i]);
        string word;
        while (ss >> word)
        {
            wordLengths.push_back(word.length());
        }
    }

    cout << "\n������ ���� ����:" << endl;
    for (int length : wordLengths)
    {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}
