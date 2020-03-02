//
// Created by npv3s on 02.03.2020.
//

#include "lib.h"

int sum(int nums_len, int *nums) {
    int out = 0;
    for (int i = 0; i < nums_len; i++) {
        out += *(nums + i);
    }
    return out;
}