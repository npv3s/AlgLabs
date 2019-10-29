#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {
    string menu[5] = { "Оливье", "Цезарь", "Блинчики", "Компот", "Булочка"};
    int prices[5] = {100, 200, 80, 20, 10};
    int amount[5];

    int i;
    for (i=0; i<5; i++) {
        cout << "Введите количество блюда \"" << menu[i] << "\": ";
        cin >> amount[i];
    }



    return 0;
}