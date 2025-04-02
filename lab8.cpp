// Задание 10
// Для произвольного текста, содержащего не более 10 строк, в каждой строке
// не более 80 символов, сформировать массив, элементы которого равны
// длинам слов. Вывести на экран исходный текст и сформированный массив.

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

    // Пример текста
    // У меня большая семья: я, мама, папа, старшая сестра, бабушка и дедушка.
    // Мы живем все вместе с собакой Бимом и кошкой Муркой в большом доме в деревне.
    // Мой папа встает раньше всех, потому что ему рано на работу.
    // Он работает доктором. Обычно бабушка готовит нам завтрак.
    // Я обожаю овсяную кашу, а моя сестра Аня – блины.

    cout << "Введите текст (не более 10 строк, каждая до 80 символов). Пустая строка завершает ввод:" << endl;
    int lineCount = 0;

    // Проверка длины строки через While
    while (lineCount < MAX_LINES)
    {
        string line;
        getline(cin, line);
        if (line.empty()) break;
        if (line.length() > MAX_LENGTH)
        {
            cout << "Превышена максимальная длина строки (80 символов), попробуйте снова." << endl;
            continue;
        }
        text[lineCount++] = line;
    }

    cout << "\nИсходный текст:" << endl;
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

    cout << "\nМассив длин слов:" << endl;
    for (int length : wordLengths)
    {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}
