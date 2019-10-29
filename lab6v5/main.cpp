#include <iostream>
#include <string>
#include <vector>
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
    struct Item {
        int index;
        string name;
        int number;
    };
    int prices[5] = {100, 200, 80, 20, 10};
    vector<Item> items;
    while (true) {
        string item;
        cout << "Введите название блюда (olivie,cesar,blinchiki,kompot,bulochka): ";
        cin >> item;
        if (item=="stop") { break;}
        items.push_back({get_ind(item), item, number});



    }
    return 0;
}