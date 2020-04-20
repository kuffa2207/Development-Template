#pragma once
#include <iostream>
#include <clocale>
#include <math.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <vector>



using namespace std;
class Date {
public:
    Date(int a);
    ~Date();
    Date(const Date&);             // копирования
    friend ostream& operator<< (ostream& s, const Date& c); // перегруженный оператор вывода
    friend istream& operator >> (istream& s, Date& c); // перегруженный оператор ввода
    void menu();
    int daysToCheck[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    Date(int d = 0, int m = 0, int y = 0, int h = 0, int t = 0)
    {
        setDate(d, m, y, h, t);
    }
    int getDay();   
    int getMonth();
    int getYear();
    int getHour();
    int getTemp();
    void setTemp(int temp);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setHour(int hour);
    void setDate(int day, int month, int year, int hour, int temp);
    static bool WrongDate(int day, int month, int year, int hour);
    static int dayInMonth(int month);
    void filein();
    void historyData();
    void firstdata();
    void fileout1day();
    void sredtemp();
private:
    int day;
    int month;
    int year;
    int hour;
    int temp;
    int high, low;
};

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
    fstream fout("C:\\iiiip\\Development-Template\\app\\term.txt", ios::binary | ios::app);
    getYear();
    getMonth();
    getDay();
    getHour();
    getTemp();
    fout << year << "." << month << "." << day << "." << hour << "   " << "Температура за этот день      " << temp << endl;
}
void Date::historyData()
{
    string line;
    ifstream in("C:\\iiiip\\Development-Template\\app\\term.txt");
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
        ifstream in("C:\\iiiip\\Development-Template\\app\\term.txt");
        string str;
        getline(in, str);
        getline(in, str);
        cout << endl;
        in.close();
        cout << str;
    }
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
}
int Date::getDay() {
N: cout << "Введите день" << endl;
    cout << "День = ";
    cin >> day;
    if (month == 2 && (day <= 1 || day >= 30))
    {
        cout << "Ошибка ввода дня (в феврале 29 дней))))\n"; goto N;
    }
    if(day<1 || day >  daysToCheck[month - 1])
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
void Date::fileout1day() {
    string file_in, word_in, word_fn;
    file_in = "C:\\iiiip\\Development-Template\\app\\term.txt";
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
        cout << "Такой даты нет" << endl;
    }
    in.close();
}

void Date::sredtemp() {
    string file_in, word_in, word_fn;
    ifstream in("C:\\iiiip\\Development-Template\\app\\term.txt");
    cout << "Введите год и месяц для которого будет расчитана средняя температура ГГГГ.ММ" << endl;
    cin >> word_fn;
    while (in >> word_in)

        if (word_in == word_fn)
        {
            in.seekg(35, ios::cur);
            getline(in, file_in);
            cout << file_in << endl;
            in.close();
        }
    if (word_in != word_fn) {
        cout << "Такой даты нет" << endl;
    }
    in.close();
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
} while (vid < 1 || vid > 6);
if (vid == 4) {
    system("CLS");
    int vid2;
    do {
        cout << "1) Средняя температура за определенный месяц" << endl;
        cout << "2) Средняя температура за все время" << endl;
        cout << "3) Назад"<< endl << endl;
        cout << "Выбор - ";
        cin >> vid2;
    } while (vid2 < 1 || vid2 > 4);
    if (vid2 == 1) {
        sredtemp();
    }
    if (vid2 == 2) {
        // Средняя температура за все время
    }
    if (vid2 == 3) {
        system("CLS");
        goto n;
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
