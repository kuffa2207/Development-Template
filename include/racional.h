#ifndef INCLUDE_racional_H_
#define INCLUDE_racional_H_
#pragma once

#include <iostream>
#include <fstream>
#include <clocale>     
#include <math.h>
using namespace std;
class number
{
public:
	int x, y;
	int numerator; //числитель
	int denominator; //знаменатель
public:
	number(int iNumerator, int iDenominator);
	number(int iNumerator);
	number();
	number(const number& ss);
	~number() {};
	number Add(const number& C);
	friend bool operator==(const number& left, const number& right) {
		bool res = 0;
		if (left.numerator == right.numerator && left.denominator == right.denominator) {
			res = 1;
		}
		else {
			res = 0;
		}
		return res;
	}
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
