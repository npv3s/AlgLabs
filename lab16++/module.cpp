//
// Created by npv3s on 06.04.2020.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include "module.h"

using namespace std;

Item to_item(const char *str) {
    Item out;
    int text_index = 0;
    memset(out.code, '\0', CODE_SIZE);
    for (; str[text_index] != ',' && text_index < CODE_SIZE; text_index++) {
        out.code[text_index] = str[text_index];
    }
    memset(out.name, '\0', NAME_SIZE);
    int local_index;
    for (local_index = 0, text_index++;
         str[text_index] != ',' && local_index < NAME_SIZE; text_index++, local_index++) {
        out.name[local_index] = str[text_index];
    }
    char amount_str[10] = {'\0'};
    for (local_index = 0, text_index++; str[text_index] != ',' && local_index < 10; text_index++, local_index++) {
        amount_str[local_index] = str[text_index];
    }
    out.amount = atoi(amount_str);
    char price_str[10] = {'\0'};
    for (local_index = 0, text_index++; str[text_index] != ',' && local_index < 10; text_index++, local_index++) {
        price_str[local_index] = str[text_index];
    }
    out.price = atoi(price_str);
    return out;
}

DB openDB(const char* f_name) {
    FILE *fp;
    if ((fp = fopen(f_name, "r")) == nullptr) {
        puts("Невозможно открыть файл");
        exit(-1);
    }

    int len = 1; // Последняя строка без '\n'
    char buff;
    char text[DB_SIZE];
    int text_index = 0;
    while ((buff = getc(fp)) != EOF) {
        if (buff == '\n') len++;
        text[text_index++] = buff;
    }
    fclose(fp);

    Item db[len];
    char *text_ptr = text;
    for (int i = 0; i < len; i++) {
        db[i] = to_item(text_ptr);
        text_ptr = strchr(text_ptr, '\n') + 1;
    }
    return DB{len, db};
}

void print_by_code(const char *code, DB data) {
    auto [len, db] = data;
    cout << "┌" << string(CODE_SIZE, '-') << "┬" << string(NAME_SIZE, '-') << "┬" << string(10, '-') << "┬"
         << string(10, '-') << "┐" << endl;
    for (int i = 0; i < len; i++) {
        if (strcmp(code, db[i].code) == 0) {
            cout << "|" << left << setw(CODE_SIZE) << db[i].code << "|" << setw(NAME_SIZE) << db[i].name << "|" << right
                 << setw(10) << db[i].amount << "|" << setw(10) << db[i].price << "|" << endl;
        }
    }
    cout << "└" << string(CODE_SIZE, '-') << "┴" << string(NAME_SIZE, '-') << "┴" << string(10, '-') << "┴"
         << string(10, '-') << "┘" << endl;
}

void print_c_code(DB data) {
    auto [len, db] = data;
    cout << "Детская одежда" << endl;
    cout << "┌" << string(CODE_SIZE, '-') << "┬" << string(NAME_SIZE, '-') << "┬" << string(10, '-') << "┬"
         << string(10, '-') << "┐" << endl;
    for (int i = 0; i < len; i++) {
        if (strncmp("C", db[i].code, 1) == 0) {
            cout << "|" << left << setw(CODE_SIZE) << db[i].code << "|" << setw(NAME_SIZE) << db[i].name << "|" << right
                 << setw(10) << db[i].amount << "|" << setw(10) << db[i].price << "|" << endl;
        }
    }
    cout << "└" << string(CODE_SIZE, '-') << "┴" << string(NAME_SIZE, '-') << "┴" << string(10, '-') << "┴"
         << string(10, '-') << "┘" << endl;
}