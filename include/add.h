#pragma once
#include <iostream>
#include <clocale>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <iomanip>

using namespace std;

class Textred {
private:
    int x, y, len;
public:
    Textred();
    Textred(const Textred& c);
    Textred(int _x, int _y);
    int menu();
    void start();
    void show(char* str);
    void text(char* str, int hir1);
    void main();
    bool operator==(const Textred& c);
    friend bool operator==(const Textred& left, const Textred& right) {
        bool res = false;
        if (left.x == right.x && left.y == right.y) {
            res = true;
        }
        else {
            res = false;
        }
        return res;
    }
};

