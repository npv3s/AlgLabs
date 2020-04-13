//
// Created by npv3s on 13.04.2020.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include "module.h"

using namespace std;

DB edit_DB(int raw, Item new_item, DB data) {
    data.table[raw] = new_item;
    return data;
}