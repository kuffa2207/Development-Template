#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>   
using namespace std;

class Polynom
{
private:
    int high, low;
public:
    int n; //степень полинома
    double* koef; //указатель на массив коэффициентов полинома koef[i] - коэффициент при i-й степени
    Polynom();
    Polynom(int an);//конструктор с параметрами
    Polynom(const Polynom&); //копирования
    ~Polynom();//деструктор
    bool operator==(const Polynom& c) {
        return (low == c.low && high == c.high);
    }
    friend bool operator==(const Polynom& c1, const Polynom& c2) {
        return (c1.low == c2.low && c1.high == c2.high);
    }
    int getn(); //функция получения степени полинома
    double getkoef(int); //функция получения коэффициента при i-й степени
    Polynom operator+(const Polynom&);   //оператор сложения двух полиномов
    Polynom operator-(const Polynom&);   //оператор вычитания двух полиномов
    Polynom operator*(const Polynom&);// оператор умножения
    Polynom operator=(const Polynom&);   //оператор присваивания
    Polynom derivative();//производная

    friend ostream& operator<< (ostream& s, const Polynom& c); // перегруженный оператор вывода
    friend istream& operator >> (istream& s, Polynom& c); // перегруженный оператор ввода
    double& operator()(int i)
    {
        return koef[i];
    }
};
