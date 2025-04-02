// ������� 12
// ���������� � ��������� ����������� � ���� �������� ������. � ������
// �����: �������, ���, ��������, ����, ������ �� ������, ����������,
// ����������������. �� ������ ����� ��� ��� �� ��������� � ��� �� �������:
// �������, ���, ��������, ���, ��� ��������. ������������� ������ �
// ����� ������ �� ����������� ���� ��������. ������� �� ����� �������
// ��������� ������� ����� ������ 18 ���.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <Windows.h>
using namespace std;

struct StudentGrades
{
    char surname[30];
    char name[30];
    char patronymic[30];
    int course;
    int physics;
    int math;
    int programming;
};

struct StudentInfo
{
    char surname[30];
    char name[30];
    char patronymic[30];
    char gender;
    int birthYear;
};

void generateDatasets()
{
    vector<StudentGrades> grades = {
            {"������", "�������", "���������", 1, 4, 5, 3},
            {"������", "�������", "��������", 2, 5, 4, 5},
            {"�������", "������", "��������", 1, 3, 3, 4},
            {"�������", "�����", "�������������", 3, 5, 5, 5},
            {"��������", "������", "��������", 1, 4, 4, 4}
    };

    vector<StudentInfo> info = {
            {"������", "�������", "���������", 'M', 2003},
            {"������", "�������", "��������", 'M', 2002},
            {"�������", "������", "��������", 'M', 2005},
            {"�������", "�����", "�������������", 'M', 2001},
            {"��������", "������", "��������", 'M', 2004}
    };

    ofstream file1("grades.dat", ios::binary);
    ofstream file2("info.dat", ios::binary);

    for (const auto& student : grades)
    {
        file1.write(reinterpret_cast<const char*>(&student), sizeof(StudentGrades));
    }
    for (const auto& student : info)
    {
        file2.write(reinterpret_cast<const char*>(&student), sizeof(StudentInfo));
    }

    file1.close();
    file2.close();
}

// ������� ��� ��������� �� ���� ��������
bool compareByBirthYear(const StudentInfo& a, const StudentInfo& b)
{
    return a.birthYear < b.birthYear;
}

int main()
{

    // ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    generateDatasets();

    vector<StudentGrades> grades;
    vector<StudentInfo> info;

    // ������ ������� �����
    ifstream file1("grades.dat", ios::binary);
    if (file1)
    {
        StudentGrades temp;
        while (file1.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
        {
            grades.push_back(temp);
        }
        file1.close();
    }

    // ������ ������� �����
    ifstream file2("info.dat", ios::binary);
    if (file2)
    {
        StudentInfo temp;
        while (file2.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
        {
            info.push_back(temp);
        }
        file2.close();
    }

    // �������� ������������ ������
    if (grades.size() != info.size())
    {
        cerr << "������: ����� �������� ������ ���������� �������!" << endl;
        return 1;
    }

    // ���������� �� ���� ��������
    vector<pair<StudentGrades, StudentInfo>> students;
    for (size_t i = 0; i < grades.size(); i++)
    {
        students.push_back({grades[i], info[i]});
    }

    sort(students.begin(), students.end(), [](const auto& a, const auto& b)
    {
        return a.second.birthYear < b.second.birthYear;
    });

    // ������ ������� � �����
    ofstream out1("grades.dat", ios::binary);
    ofstream out2("info.dat", ios::binary);
    for (const auto& student : students)
    {
        out1.write(reinterpret_cast<const char*>(&student.first), sizeof(StudentGrades));
        out2.write(reinterpret_cast<const char*>(&student.second), sizeof(StudentInfo));
    }
    out1.close();
    out2.close();

    // ����� ��������� 1 ����� ������ 18 ���
    cout << "�������� 1 ����� ������ 18 ���:" << endl;
    for (const auto& student : students)
    {
        if (student.first.course == 1 && (2024 - student.second.birthYear) > 18)
        {
            cout << student.first.surname << " " << student.first.name << " " << student.first.patronymic << endl;
        }
    }

    return 0;
}
