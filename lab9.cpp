// Задание 11
// На основе записной книжки, содержащей сведения о людях (фамилия, год
// рождения, адрес - город, улица, номер дома, квартиры, место работы или учебы),
// вывести на печать по алфавиту фамилии лиц, живущих в Красноярске.


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

// Функция для сортировки фамилий по алфавиту
bool compareBySurname(const Person& a, const Person& b)
{
    return a.surname < b.surname;
}

int main() {

    // Кодировка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Person> notebook = {
            {"Иванов", 1990, {"Красноярск", "Ленина", 12, 34}, "Инженер"},
            {"Петров", 1985, {"Москва", "Арбат", 5, 10}, "Программист"},
            {"Сидоров", 1992, {"Красноярск", "Мира", 8, 22}, "Студент"},
            {"Федоров", 2000, {"Санкт-Петербург", "Невский", 17, 4}, "Дизайнер"},
            {"Алексеев", 1988, {"Красноярск", "Советская", 10, 15}, "Учитель"},
            {"Захаров", 1995, {"Красноярск", "Парковая", 3, 45}, "Врач"},
            {"Морозов", 1975, {"Новосибирск", "Красная", 20, 5}, "Бухгалтер"},
            {"Кузнецов", 1983, {"Красноярск", "Гагарина", 7, 12}, "Юрист"},
            {"Смирнов", 1998, {"Красноярск", "Победы", 1, 8}, "Студент"},
            {"Попов", 1991, {"Екатеринбург", "Центральная", 11, 9}, "Менеджер"}
    };

    // Отбор людей из Красноярска
    vector<Person> krasnoyarskResidents;
    for (const auto& person : notebook)
    {
        if (person.address.city == "Красноярск")
        {
            krasnoyarskResidents.push_back(person);
        }
    }

    // Сортировка по фамилии
    sort(krasnoyarskResidents.begin(), krasnoyarskResidents.end(), compareBySurname);

    // Вывод списка
    cout << "Люди, живущие в Красноярске (отсортированные по фамилии):" << endl;
    for (const auto& person : krasnoyarskResidents)
    {
        cout << person.surname << endl;
    }

    return 0;
}
