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

void print_c_code(DB data) {
    auto[len, db] = data;
    cout << "Детская одежда" << endl;
    cout << "┌" << string(CODE_SIZE, '-') << "┬" << string(NAME_SIZE, '-') << "┬" << string(10, '-') << "┬"
         << string(10, '-') << "┐" << endl;
    cout << "|" << left << setw(CODE_SIZE) << "Code" << "|" << setw(NAME_SIZE) << "Name" << "|" << setw(10) << "Amount"
         << "|" << setw(10) << "Price" << "|" << endl;
    cout << "├" << string(CODE_SIZE, '-') << "┼" << string(NAME_SIZE, '-') << "┼" << string(10, '-') << "┼"
         << string(10, '-') << "┤" << endl;
    for (int i = 0; i < len; i++) {
        if (strncmp("C", db[i].code, 1) == 0) {
            cout << "|" << left << setw(CODE_SIZE) << db[i].code << "|" << setw(NAME_SIZE) << db[i].name << "|" << right
                 << setw(10) << db[i].amount << "|" << setw(10) << db[i].price << "|" << endl;
        }
    }
    cout << "└" << string(CODE_SIZE, '-') << "┴" << string(NAME_SIZE, '-') << "┴" << string(10, '-') << "┴"
         << string(10, '-') << "┘" << endl;
}

void create_DB(const char *f_name, DB data) {
    FILE * fp;
    fp = fopen (f_name,"wt");

    for(int i = 0; i < data.len; i++){
        Item* raw = &data.table[i];
        fprintf (fp, "%s,%s,%d,%d\n", raw->code, raw->name, raw->amount, raw->price);
    }
    fclose (fp);
}

void explore_DB(const char *f_name) {
    auto[len, db] = openDB(f_name);
    cout << "┌" << string(CODE_SIZE, '-') << "┬" << string(NAME_SIZE, '-') << "┬" << string(10, '-') << "┬"
         << string(10, '-') << "┐" << endl;
    cout << "|" << left << setw(CODE_SIZE) << "Code" << "|" << setw(NAME_SIZE) << "Name" << "|" << setw(10) << "Amount"
         << "|" << setw(10) << "Price" << "|" << endl;
    cout << "├" << string(CODE_SIZE, '-') << "┼" << string(NAME_SIZE, '-') << "┼" << string(10, '-') << "┼"
         << string(10, '-') << "┤" << endl;
    for (int i = 0; i < len; i++) {
        cout << "|" << left << setw(CODE_SIZE) << db[i].code << "|" << setw(NAME_SIZE) << db[i].name << "|" << right
             << setw(10) << db[i].amount << "|" << setw(10) << db[i].price << "|" << endl;
    }
    cout << "└" << string(CODE_SIZE, '-') << "┴" << string(NAME_SIZE, '-') << "┴" << string(10, '-') << "┴"
         << string(10, '-') << "┘" << endl;
}

bool str_compare(const char *str1, const char *str2, int char_size) {
    for(int i = 0; i < char_size; i++) {
        if ((int)str1[i] < (int)str2[i]) return true;
    }
    return false;
}

DB add_to_DB(Item new_raw, DB data) {
    auto[len, db] = data;
    Item new_db[len+1];
    int i;
    for(i = 0; i < len+1; i++) {
        if (str_compare(db[i].code, new_raw.code, CODE_SIZE)) {
            break;
        }
        new_db[i] = db[i];
    }
    new_db[i] = new_raw;
    for(; i < len+1; i++) {
        new_db[i+1] = db[i];
    }
    return DB{len, new_db};
}

void clear_DB(const char *f_name) {
    FILE * fp;
    fp = fopen (f_name,"w");
    fclose(fp);
}

DB edit_DB(int raw, Item new_item, DB data) {
    data.table[raw] = new_item;
    return data;
}
