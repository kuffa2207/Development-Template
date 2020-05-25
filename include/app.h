#ifndef INCLUDE_Game_H_
#define INCLUDE_Game_H_
#include <iostream>
#include <ctime>
#define MAX 9
using namespace std;
class BullAndCow {
public:
    void bullCow();
    void SetNom(char* number) {
        for (int i = 0; i < count; i++) {
            pc_num[i] = number[i];
        }
    }
    void MassNum(int value, char Mass[], int number);
     BullAndCow(int i);
     BullAndCow() { count = 0; }
    ~ BullAndCow() {}
    bool similarNum(char Mass[], int number);
    void PCrand(char Mass[], int number);
private:
    char pc_num[99999];
    char me[99999];
    int count = 0;
    int Bull = 0;
    int Cow = 0;
    int number;
};
#endif  // INCLUDE_Game_H_
