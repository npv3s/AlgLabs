//
// Created by npv3s on 06.04.2020.
//

#ifndef LAB16___MODULE_H
#define LAB16___MODULE_H

#define CODE_SIZE 4
#define NAME_SIZE 32
#define DB_SIZE 65535

struct Item {
    char code[CODE_SIZE];
    char name[NAME_SIZE];
    int amount;
    int price;
};

struct DB {
    int len;
    Item* table;
};

Item to_item(const char *str);
DB openDB(const char *f_name);
void print_by_code(const char *str, DB data);
void print_c_code(DB data);

#endif //LAB16___MODULE_H
