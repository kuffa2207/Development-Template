#include "term.h"
#include <iostream>
#include <clocale>
#include <math.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

Date::~Date() {

}
void Date::setTemp(int temp)
{
    this->temp = temp;
}
void Date::setDay(int day)
{
    this->day = day;
}
void Date::setMonth(int month)
{
    this->month = month;
}
void Date::setYear(int year)
{
    this->year = year;
}
void Date::setHour(int hour)
{
    this->hour = hour;
}
bool Date::WrongDate(int day, int month, int year, int hour)
{
    if ((day < 1 || day>31) || (month < 1 || month>12) || (hour <= 0 || hour > 24))
    {
    }
    return true;
}
int Date::dayInMonth(int month)
{
    int days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    return days[month - 1];
}
void Date::filein() {
    fstream fout("term.txt", ios::binary | ios::app);
    getYear();
    getMonth();
    getDay();
    getHour();
    getTemp();
    fout << year << "." << month << "." << day << "." << hour << "   " << "Температура за этот день " << temp << endl;
}
void Date::historyData()
{
    string line;
    ifstream in("term.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();
    cout << "История Наблюдения за все время" << endl;
}
void Date::firstdata() {
    {
        ifstream in("term.txt");
        string str;
        getline(in, str);
        getline(in, str);
        cout << endl;
        in.close();
        cout << str;
    }
}
void Date::fileout1day() {
    string file_in, word_in, word_fn;
    file_in = "term.txt";
    ifstream in(file_in.c_str(), ios::in);
    cout << "Введите дату и время в Формате ГГГГ.ММ.ДД.ЧЧ:" << endl;
    cin >> word_fn;
    while (in >> word_in)
        if (word_in == word_fn)
        {
            in.seekg(4, ios::cur);
            getline(in, file_in);
            cout << file_in << endl;
            in.close();
        }
    if (word_in != word_fn) {
        cout << "Такой даты нет";
    }
    in.close();
}
void Date::setDate(int day, int month, int year, int hour, int temp)
{
    if (WrongDate(day, month, year, hour))
    {
        setDay(day);
        setMonth(month);
        setYear(year);
        setHour(hour);
        setTemp(temp);
    }
    else {
        throw string("Ne verno");
    }
}
int Date::getDay() {
N: cout << "Введите день" << endl;
    cout << "День = ";
    cin >> day;
    if (month == 2 && (day <= 1 || day >= 29))
    {
        cout << "Ошибка ввода дня (в феврале 29 дней))))\n"; goto N;
    }
    if (day<1 || day >  daysToCheck[month - 1])
    {
        cout << "Ошибка ввода дня (в феврале 29 дней))))\n"; goto N;
    }
    return true;
}
int Date::getMonth() {
N1: cout << "Введите Месяц" << endl;
    cout << "Месяц = ";
    cin >> month;
    if (month < 1 || month>12)
    {
        cout << "Ошибка ввода Месяца\n"; goto N1;
    }
    return true;
}
int Date::getYear() {
N2: cout << "Введите Год" << endl;
    cout << "Год = ";
    cin >> year;
    if (year < 0)
    {
        cout << "Ошибка ввода Года\n"; goto N2;
    }
    return true;
}
int Date::getHour() {
N2: cout << "Введите час" << endl;
    cout << "Час = ";
    cin >> hour;
    if (hour > 24 || hour <= 0)
    {
        cout << "Ошибка ввода времени\n"; goto N2;
    }
    return true;
}
int Date::getTemp() {
N2: cout << "Введите Температуру" << endl;
    cout << "Температура = ";
    cin >> temp;
    return true;
}

void Date::menu() {
    int vid;
    int year = 1, month = 1, day = 1, hour = 1;
n: do {
    cout << "1) Вывести историю наблюдения из файла " << endl;
    cout << "2) Добавить новое наблюдение в файл " << endl;
    cout << "3) Узнать температуру за определенную дату и час" << endl;
    cout << "4) Меню: Средняя температура " << endl;
    cout << "5) Вывести первое наблюдение" << endl;
    cout << "6) Выход " << endl << endl;
    cout << "Выбор - ";
    cin >> vid;
} while (vid < 1 || vid > 5);
if (vid == 4) {
    system("CLS");
    int vid2;
    do {
        cout << "1) Средняя температура за определенную дату" << endl;
        cout << "2) Средняя температура за определенный месяц" << endl;
        cout << "3) Средняя температура за все время" << endl;
        cin >> vid2;
    } while (vid2 < 1 || vid2 > 3);
    if (vid2 == 1) {
        // Средняя температура за определенную дату
    }
    if (vid2 == 2) {
        // Средняя температура за определенный месяц
    }
    if (vid2 == 3) {
        // Средняя температура за все время
    }

}
if (vid == 1) {
    system("CLS");
    historyData();
    cout << endl;
    cout << "Выберите дальнейшее действие" << endl << endl;
    goto n;
}
if (vid == 2) {
    system("CLS");
    filein();
    cout << endl;
    cout << "Выберите дальнейшее действие" << endl << endl;
    goto n;
}
if (vid == 3) {
    system("CLS");
    fileout1day();
    cout << "Выберите дальнейшее действие" << endl << endl;
    goto n;
}
if (vid == 5) {
    system("CLS");
    firstdata();
    cout << endl;
    cout << "Выберите дальнейшее действие" << endl << endl;
    goto n;
}
if (vid == 6) {
    exit;
}

}