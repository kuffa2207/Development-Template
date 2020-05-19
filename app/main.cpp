#include "add.h"
using namespace std;


int main() {
    system("chcp 1251 >> null"); // Без понятия, как это работает, но спасибо тому челу на киберфоруме, до слез просто
    setlocale(LC_ALL, "Russian");
    SetConsoleTitle(L"Текстовый Редактор");
    Textred a;
    a.main();
}
