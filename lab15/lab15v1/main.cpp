#include <cstdio>
#include <cstring>
#include "lib.h"
using namespace std;

#define FILENAME "/mnt/c/Users/npv3s/Desktop/psycho.txt"

int main() {
    FILE *fp;
    if ((fp = fopen(FILENAME, "r")) == nullptr) {
        puts("Невозможно открыть файл");
        return -1;
    }

    char text[2048] = {'\0'};
    int text_index = 0;
    char buff;
    while ((buff = getc(fp)) != EOF) {
        text[text_index] = buff;
        text_index++;
    }
    fclose(fp);

    int points_len = text_processing(text, text_index);

    FILE *fw;
    if ((fw = fopen(FILENAME, "w")) == nullptr) {
        puts("Невозможно открыть файл");
        return -1;
    }
    fprintf(fw, "%d %s", points_len, text);
    fclose(fw);

    return 0;
}