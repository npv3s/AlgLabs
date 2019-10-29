#include <iostream>
#include <string>
using namespace std;

int main() {
    enum Menu {
        olivie=150,
        cesar=120,
        blinchiki=80,
        kompot=20,
        bulochka=10
    };
    while (true) {
        string item;
        cout << "Введите название блюда (olivie,cesar,blinchiki,kompot,bulochka): ";
        cin >> item;
        if (item=="stop") { break;}
        

    }
    return 0;
}