//
// Created by npv3s on 13.04.2020.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include "module.h"

using namespace std;

void print_by_code(const char *code, DB data) {
    auto[len, db] = data;
    cout << "┌" << string(CODE_SIZE, '-') << "┬" << string(NAME_SIZE, '-') << "┬" << string(10, '-') << "┬"
         << string(10, '-') << "┐" << endl;
    cout << "|" << left << setw(CODE_SIZE) << "Code" << "|" << setw(NAME_SIZE) << "Name" << "|" << setw(10) << "Amount"
         << "|" << setw(10) << "Price" << "|" << endl;
    cout << "├" << string(CODE_SIZE, '-') << "┼" << string(NAME_SIZE, '-') << "┼" << string(10, '-') << "┼"
         << string(10, '-') << "┤" << endl;
    for (int i = 0; i < len; i++) {
        if (strcmp(code, db[i].code) == 0) {
            cout << "|" << left << setw(CODE_SIZE) << db[i].code << "|" << setw(NAME_SIZE) << db[i].name << "|" << right
                 << setw(10) << db[i].amount << "|" << setw(10) << db[i].price << "|" << endl;
        }
    }
    cout << "└" << string(CODE_SIZE, '-') << "┴" << string(NAME_SIZE, '-') << "┴" << string(10, '-') << "┴"
         << string(10, '-') << "┘" << endl;
}