#include <cstdio>

bool isSpecial(char symbol) {
    return symbol < 32;
}

int main() {
    FILE *fp;
    if ((fp = fopen("/mnt/c/Users/npv3s/Desktop/psycho2.txt", "r")) == nullptr) {
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

    for(int i = 0; i < 2048; i++) {
        if (text[i] == ' ') {
            for(int y = i; y < 2047; y++) {
                text[y] = text[y+1];
            }
            text[2047] = '\0';
        }
    }
    int the_end = 0;
    for (; text[the_end] != '\0'; the_end++) {}
    printf("Длина текста: %d символов", the_end);

    FILE *fw;
    if ((fw = fopen("/mnt/c/Users/npv3s/Desktop/psycho2.txt", "w")) == nullptr) {
        puts("Невозможно открыть файл");
        return -1;
    }
    fprintf(fw, "%s", text);
    fclose(fw);

    return 0;
}