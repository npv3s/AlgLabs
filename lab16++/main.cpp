#include <iostream>
#include "module.h"

using namespace std;


int main() {
    auto db = openDB("../db.csv");

    char code[CODE_SIZE];
    cout << "Введите артикул: " << endl;
    cin >> code;
    print_by_code(code, db);
    print_c_code(db);

    return 0;
}
