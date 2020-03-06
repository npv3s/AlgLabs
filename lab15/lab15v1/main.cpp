#include <cstdio>
#include <cstring>
#include <iostream>
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

    int points_index[256];

    int points_len = 0;
    for(int i = 0; i < text_index; i++) {
        if (text[i] == '.') { points_index[points_len++] = i; }
    }

    for (int i = points_len-1; i > 0; i--) {
        for (int y = points_index[i-1]+2; y < points_index[i]+2; y++) {
            printf("%c",text[y]);
        }
    }
    for (int y = 0; y < points_index[0]+2; y++) {
        printf("%c",text[y]);
    }

    FILE *fw;
    if ((fw = fopen(FILENAME, "w")) == nullptr) {
        puts("Невозможно открыть файл");
        return -1;
    }
    fprintf(fw, "%d %s", points_len, text);
    fclose(fw);

    return 0;
}