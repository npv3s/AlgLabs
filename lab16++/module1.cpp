//
// Created by npv3s on 13.04.2020.
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

DB openDB(const char *f_name) {
    FILE *fp;
    if ((fp = fopen(f_name, "r")) == nullptr) {
        puts("Невозможно открыть файл");
        exit(-1);
    }

    int len = 0; // Последняя строка с '\n'
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