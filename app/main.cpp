#include "add.h"
using namespace std;


int main() {
        setlocale(LC_ALL, "Russian");
        SetConsoleTitle("Текстовый Редактор");
        char str[400];
        Textred a;
        int x1 = a.menu();
        a.start();
        a.text(str, x1);
        a.show(str);
}
