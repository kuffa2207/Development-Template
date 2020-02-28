#include "racional.h"
#include <iostream>
#include <fstream>
#include <clocale>     
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	number c0, c1, c2, c3, c4;
	cout << "c0" << endl;
	c0.inPut();
	cout << "c1" << endl;
	c1.inPut();
	cout << "c2" << endl;
	c2.inPut();
	cout << "c3" << endl;
	c3.inPut();
	cout << "c4" << endl;
	c4.inPut();


	number* pc0 = new number(c0);                        // по умолчанию
	number* pc1 = new number(c1);                // инициализация
	number* pc3 = new number(c2);                      // копирования
	number* pc4 = new number(c3);                     // преобразования типа

	number c5;
	c5 = c2;                                            // применение перегруженой операции присваивания
	cout << "Результат применения присваивания c2 новой переменной: с5 = ";
	c5.output();
	cout << endl;

	cout << "Сравнение дроби c1 и c3 дроби ";
	cout << endl;
	if (c1 == c3) {
		c1.output();
		cout << " == ";
		c3.output();
		cout << endl;
		cout << endl;
	}
	else {
		c1.output();
		cout << " != ";
		c3.output();
		cout << endl;
		cout << endl;
	}
	number c6;
	c6 = c3.Add(c2);                                    // применение функции сложения
	cout << "Результат сложения дроби с2 и дроби с3 = ";
	c6.output();
	cout << endl;
	cout << endl;

	number c7;
	c7 = c3 + c2;                                       // применение перегруженой операции сложения
	cout << "Результат сложения дроби c3 и дроби с2 = ";
	c7.output();
	cout << endl;
	cout << endl;

	number c9;
	c9 = c3 * c3;
	cout << "Результат умножения дроби с3 и дроби с3 = ";
	c9.output();
	cout << endl;
	cout << endl;

	number c10;
	c10 = c7 - c4;
	cout << "Результат вычитания дроби с4 из дроби с7 = ";
	c10.output();
	cout << endl;
	cout << endl;

	number c11;
	c11 = c1 / c2;
	cout << "Результат деления дроби с1 и дроби с2 = ";
	c11.output();
	cout << endl;
	cout << endl;

	return 0;
}

