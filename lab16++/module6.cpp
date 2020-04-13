//
// Created by npv3s on 13.04.2020.
//

#include "module.h"

using namespace std;

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