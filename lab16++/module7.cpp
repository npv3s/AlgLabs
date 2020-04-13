//
// Created by npv3s on 13.04.2020.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include "module.h"

using namespace std;

void clear_DB(const char *f_name) {
    FILE * fp;
    fp = fopen (f_name,"w");
    fclose(fp);
}