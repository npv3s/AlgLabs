#include <iostream>
#include "module.h"

using namespace std;


int main() {
    auto db = openDB("../db.csv");

    int work_mode;
    cout << "Выберети режим работы:\n"
            "1. Вывести одежду с требуемым кодом\n"
            "2. Вывести детскую одежду" << endl;
    cin >> work_mode;

    if (work_mode == 1) {
        char code[CODE_SIZE];
        cout << "Введите артикул: " << endl;
        cin >> code;
        print_by_code(code, db);
    }
    if (work_mode == 2) print_c_code(db);

    return 0;
}
