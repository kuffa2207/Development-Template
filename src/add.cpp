#include "add.h"
using namespace std;

Textred::Textred() {
    x = 1;
    y = 1;
}

Textred::Textred(const Textred& c) {
    x = c.x;
    y = c.y;
}
Textred::Textred(int _x, int _y) {
    x = _x;
    y = _y;
}

bool Textred::operator==(const Textred& c) {
    bool res = 0;
    if (x == c.x && y == c.y) {
        res = 1;
    }
    else {
        res = 0;
    }
    return res;
}

int Textred::menu() {
    int vid;
    int x, y, x1, y1;
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, 200, 200, 600, 230, NULL);
    cout << "Положение по X не более 1500 = ";
    cin >> x;
    if (x > 1500 || x < 0) {
        throw std::logic_error("Input error: wrong input parametrs to size of window!");
    }
    cout << "Положение по Y не более 1000 = ";
    cin >> y;
    if (y > 1000 || y < 0) {
        throw std::logic_error("Input error: wrong input parametrs to size of window!");
    }
    SetWindowPos(window_header, HWND_TOP, x, y, 600, 230, NULL);
    do {
        cout << "1) Ввести размер окна текстового редактора самостоятельно" << endl;
        cout << "2) 600х200" << endl;
        cout << "3) 700х600" << endl;
        cout << "4) 900х700" << endl;
        cin >> vid;
    } while (vid < 1 || vid > 4);
    system("CLS");
    if (vid == 1) {
            cout << "Введите размер окна текстового редактора в пикселях" << endl;
            cout << "Ширина = " << endl;
            cin >> x1;
            cout << "Высота = " << endl;
            cin >> y1;
            HWND window_header = GetConsoleWindow();
            SetWindowPos(window_header, HWND_TOP, x, y, x1, y1, NULL);
    }
    if (vid == 2) {
        HWND window_header = GetConsoleWindow();
        x1= 600;
        SetWindowPos(window_header, HWND_TOP, 400, 200, x1, 200, NULL);
    }
    if (vid == 3) {
        HWND window_header = GetConsoleWindow();
        x1= 700;
        SetWindowPos(window_header, HWND_TOP, 400, 200, x1, 600, NULL);
    }
    if (vid == 4) {
        HWND window_header = GetConsoleWindow();
        x1= 900;
        SetWindowPos(window_header, HWND_TOP, 400, 200, x1, 700, NULL);
    }
    system("CLS");
    return x1;
}
void Textred::start() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos;
    cursorPos.X = 27;
    cursorPos.Y = 0;
    SetConsoleCursorPosition(hStdOut, cursorPos);
    cout << "Текстовый редактор" << endl;
    cursorPos.X = 0;
    cursorPos.Y = 1;
    cout << "Для завершения записи поставьте точку в конце и нажмите Enter" << endl;
    cursorPos.X = 2;
    cursorPos.Y = 2;
    SetConsoleCursorPosition(hStdOut, cursorPos);
}
void Textred::text(char* str, int _x) {
    if (_x < 600 || _x >1500) {
        throw logic_error("Error diaposon window text");
    }
    else {
        if (_x == 600) {
            cin.getline(str, 76, '.');
        }
        else {
            if (_x == 700) {
                cin.getline(str, 131, '.');
            }
            else {
                if (_x == 900) {
                    cin.getline(str, 201, '.');
                }
                else {
                    if (_x < 800) {
                        double k = 7.75;
                        cin.getline(str, _x / k, '.');
                    }
                    else {
                        if (_x < 1000 && _x >= 800) {
                            double k = 7.68;
                            cin.getline(str, _x / k, '.');
                        }
                        else {
                            if (_x < 1200 && _x >= 1000) {
                                double k = 7.57;
                                cin.getline(str, _x / k, '.');
                            }
                            else {
                                double k = 7.48;
                                cin.getline(str, _x / k, '.');
                            }
                        }
                    }
                }
            }
        }
    }
}
void Textred::main() {
    Textred a;
    char str[400];
    int x1 = a.menu();
    a.start();
    a.text(str, x1);
    system("CLS");
    a.show(str);
}

void Textred::show(char* str) {
    int s;
    do {
        cout << "Ваш текст:" << endl;
        cout << "________________________________" << endl;
        cout << str << "." << endl;
        cout << "________________________________" << endl;
        cout << endl;
        cout << "1) Скрыть редактор" << endl;
        cout << "2) Ввести заново" << endl;
        cout << "3) Завершить работу" << endl;
        cin >> s;
        if (s == 1) {
            HWND hWnd = GetConsoleWindow();
            ShowWindow(hWnd, SW_MINIMIZE);
        }
        if (s == 2) {
            cout << "Повторный ввод" << endl;
            system("CLS");
            main();
        }
        if (s == 3) {
            system("pause");
        }
    } while (s != 3);
}