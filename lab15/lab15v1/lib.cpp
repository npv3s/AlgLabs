//
// Created by npv3s on 06.03.2020.
//

#include <cstdio>
#include "lib.h"

int text_processing(char text[2048], int text_index) {

    int points_index[256];

    int points_len = 0;
    for (int i = 0; i < text_index; i++) {
        if (text[i] == '.') {
            points_index[points_len++] = i;
        }
    }

    for (int i = points_len - 1; i > 0; i--) {
        for (int y = points_index[i - 1] + 2; y < points_index[i] + 2; y++) {
            printf("%c", text[y]);
        }
    }
    for (int y = 0; y < points_index[0] + 2; y++) {
        printf("%c", text[y]);
    }

    return points_len;
}
