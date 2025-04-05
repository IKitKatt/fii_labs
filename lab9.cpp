// ������� 11
// �� ������ �������� ������, ���������� �������� � ����� (�������, ���
// ��������, ����� - �����, �����, ����� ����, ��������, ����� ������ ��� �����),
// ������� �� ������ �� �������� ������� ���, ������� � �����������.


#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Address
{
    string city;
    string street;
    int houseNumber;
    int apartmentNumber;
};

struct Person
{
    string surname;
    int birthYear;
    Address address;
    string workOrStudy;
};

// ������� ��� ���������� ������� �� ��������
bool compareBySurname(const Person& a, const Person& b)
{
    return a.surname < b.surname;
}

int main() {

    // ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Person> notebook = {
            {"������", 1990, {"����������", "������", 12, 34}, "�������"},
            {"������", 1985, {"������", "�����", 5, 10}, "�����������"},
            {"�������", 1992, {"����������", "����", 8, 22}, "�������"},
            {"�������", 2000, {"�����-���������", "�������", 17, 4}, "��������"},
            {"��������", 1988, {"����������", "���������", 10, 15}, "�������"},
            {"�������", 1995, {"����������", "��������", 3, 45}, "����"},
            {"�������", 1975, {"�����������", "�������", 20, 5}, "���������"},
            {"��������", 1983, {"����������", "��������", 7, 12}, "�����"},
            {"�������", 1998, {"����������", "������", 1, 8}, "�������"},
            {"�����", 1991, {"������������", "�����������", 11, 9}, "��������"}
    };

    // ����� ����� �� �����������
    vector<Person> krasnoyarskResidents;
    for (const auto& person : notebook)
    {
        if (person.address.city == "����������")
        {
            krasnoyarskResidents.push_back(person);
        }
    }

    // ���������� �� �������
    sort(krasnoyarskResidents.begin(), krasnoyarskResidents.end(), compareBySurname);

    // ����� ������
    cout << "����, ������� � ����������� (��������������� �� �������):" << endl;
    for (const auto& person : krasnoyarskResidents)
    {
        cout << person.surname << endl;
    }

    return 0;
}
