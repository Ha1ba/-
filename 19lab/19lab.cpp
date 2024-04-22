#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Структура для хранения информации о человеке
struct Person {
    string fullName;
    string phoneNumber;
    int birthDate[3]; // Массив из трех чисел: день, месяц, год

    // Конструктор для инициализации
    Person(string fullName, string phoneNumber, int day, int month, int year) {
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        birthDate[0] = day;
        birthDate[1] = month;
        birthDate[2] = year;
    }

    // Функция для сравнения дат рождения для сортировки
    static bool compareByBirthDate(const Person& a, const Person& b) {
        if (a.birthDate[2] != b.birthDate[2])
            return a.birthDate[2] > b.birthDate[2]; // Сначала сравниваем год
        if (a.birthDate[1] != b.birthDate[1])
            return a.birthDate[1] > b.birthDate[1]; // Затем месяц
        return a.birthDate[0] > b.birthDate[0]; // Наконец, день
    }
};

int main() {
    vector<Person> records;

    // Запрос первоначального ввода данных
    cout << "Введите данные о людях (ФИО, номер телефона, день рождения в формате ДД ММ ГГГГ), для завершения введите 'end':" << endl;
    while (true) {
        string name, phone;
        int day, month, year;
        cout << "Введите ФИО: ";
        getline(cin, name);
        if (name == "end")
            break;
        cout << "Введите номер телефона: ";
        getline(cin, phone);
        cout << "Введите день рождения (ДД ММ ГГГГ): ";
        cin >> day >> month >> year;
        cin.ignore(); // Очистка буфера ввода после cin
        records.push_back(Person(name, phone, day, month, year));
    }

    // Сортировка записей по дате рождения в порядке убывания
    sort(records.begin(), records.end(), Person::compareByBirthDate);

    // Вывод отсортированного списка
    cout << "Отсортированный список:" << endl;
    for (const auto& person : records) {
        cout << "ФИО: " << person.fullName << ", номер телефона: " << person.phoneNumber << ", день рождения: " << person.birthDate[0] << " " << person.birthDate[1] << " " << person.birthDate[2] << endl;
    }

    // Поиск информации о людях, родившихся в одно и тоже число
    int searchDay;
    cout << "Введите день для поиска именинников: ";
    cin >> searchDay;

    vector<Person> birthdayPeople;
    for (const auto& person : records) {
        if (person.birthDate[0] == searchDay) {
            birthdayPeople.push_back(person);
        }
    }

    // Вывод списка именинников
    if (birthdayPeople.empty()) cout << "В этот день никто не родился(((" << endl;
    else
    {
        cout << "Список именинников, родившихся " << searchDay << " числа:" << endl;
        for (const auto& person : birthdayPeople)
        {
            cout << "ФИО: " << person.fullName << ", номер телефона: " << person.phoneNumber << endl;
        }
    }

    return 0;
}