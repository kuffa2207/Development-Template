#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_

#pragma once
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using namespace std;

class Date {
    friend class Term;
private:
    int* YMD;
    int T;
public:
    Date();
    ~Date();
    Date(int* _YMD, int _T);
    Date(const Date& c);
    void getdate();
    friend bool operator==(const Date& left, const Date& right) {
        bool res = false;
        if (left.YMD[0] == right.YMD[0] && left.T == right.T &&
            left.YMD[1] == right.YMD[1] && left.YMD[2] == right.YMD[2]) {
            res = true;
        }
        else {
            res = false;
        }
        return res;
    }
    Date operator=(Date& c);
};

class Term {
private:
    int count = 0;
    Date* num;
public:
    Term();
    ~Term();
    Term(int* YMD, int T);
    Term(const Term& c);
    Term operator=(Term& c);
    friend bool operator==(const Term& left, const Term& right) {
        bool res = false;
        if (left.count == right.count) {
            res = true;
        }
        else {
            res = false;
        }
        return res;
    }
    void setdate(Date new_YMD);
    void showsredall(int tr);
    int info();
    int sredm(int month);
    void infile();
    void outfile();
    void firstdata();
    void show_sredm(int month);
    int sredall(int tr);
    int inpmonth();
    int returnday();
    int returnmonth();
    int returnyear();
    int returnhour();
    void menu();
};
#endif  // INCLUDE_ADD_H_
