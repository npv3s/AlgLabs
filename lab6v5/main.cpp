#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int get_ind(string item) {
    string menu[5] = { "olivie", "cesar", "blinchiki", "kompot", "bulochka"};
    int i = 0;
    for (i=0; i<5; i++) {
        if (menu[i] == item) {
            goto exit;
        }
    }
    throw invalid_argument( "No such element!" );
    exit:
    return i;
}


int main() {
    string menu[5] = { "olivie", "cesar", "blinchiki", "kompot", "bulochka"};
    int prices[5] = {100, 200, 80, 20, 10};
    while (true) {
        string item;
        cout << "Введите название блюда (olivie,cesar,blinchiki,kompot,bulochka): ";
        cin >> item;
        if (item=="stop") { break;}


    }
    return 0;
}