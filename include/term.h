#pragma once
#include <iostream>
#include <clocale>
#include <math.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Windows.h>

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
