#ifndef INCLUDE_racional_H_
#define INCLUDE_racional_H_
#pragma once

#include <iostream>
#include <fstream>
#include <clocale>     
#include <math.h>
using namespace std;
int x, y;
class number
{
public:
	int numerator; //числитель
	int denominator; //знаменатель
public:
	number(int iNumerator, int iDenominator);
	number(int iNumerator);
	number();
	number(const number& ss);
	~number() {};
	number Add(const number& C);

	number operator +(number& C);
	number operator -(number& C);
	number operator *(number& C);
	number operator /(number& C);
	bool operator==(const number& c);
	void cancellation();//сокращает дробь
	void output();
	void inPut();
};

#endif  // INCLUDE_ADD_H_
