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
    do {
        cout << "Положение по X не более 1500 = ";
        cin >> x;
        cout << "Положение по Y не более 1000 = ";
        cin >> y;
    } while (x > 1500 || y>1000);
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
 

void Textred::show(char* str) {
    int s;
    do {
        cout << "Ваш текст:" << endl;
        cout << str << "." << endl;
        cout << "1) Скрыть редактор" << endl;
        cout << "2) Завершить работу";
        cin >> s;
        if (s != 1 || s != 2) {
            system("CLS");
        }
        if (s == 1) {
            HWND hWnd = GetConsoleWindow();
            ShowWindow(hWnd, SW_MINIMIZE);
        }
    } while (s != 2);
    if (s == 2) {
        system("pause");
    }
}