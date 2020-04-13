//
// Created by npv3s on 13.04.2020.
//

#include <iostream>
#include "module.h"

using namespace std;

void create_DB(const char *f_name, DB data) {
    FILE * fp;
    fp = fopen (f_name,"wt");

    for(int i = 0; i < data.len; i++){
        Item* raw = &data.table[i];
        fprintf (fp, "%s,%s,%d,%d\n", raw->code, raw->name, raw->amount, raw->price);
    }
    fclose (fp);
}