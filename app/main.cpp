#include "polinom.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void main()
{
    setlocale(LC_ALL, "");
    int n, m;
    cout << "Введите степень полинома:" << '\n';
    cout << "N = ";
    cin >> n;
    Polynom A(n), D, K, Y;
    cout << "Введите коэфициенты полинома:" << '\n';
    cin >> A;
    cout << setw(17) << "Полином А:" << setw(5) << A << '\n';
    cout << setw(17) << "Новый полином D=A+A:" << setw(5) << (D = A + A) << '\n';
    cout << setw(17) << "Новый полином K=A-A:" << setw(5) << (K = A - A) << '\n';
    cout << setw(17) << "Производная от полинома:" << setw(5) << A.derivative() << '\n';
    cout << setw(17) << "Новый полином Y=A*A:" << setw(5) << (Y = A * A) << '\n';
    system("pause");
}
