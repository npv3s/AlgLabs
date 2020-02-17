#include <cstdio>

bool isSpecial(char symbol) {
    return symbol < 32;
}

int main() {
    FILE *fp;
    if ((fp = fopen("/mnt/c/Users/npv3s/Desktop/psycho.txt", "r")) == nullptr) {
        puts("Невозможно открыть файл");
        return -1;
    }

    char text[2048] = {'\0'};
    int  text_index = 0;
    char buff;
    while ((buff = getc(fp)) != EOF) {
        text[text_index] = buff;
        text_index++;
    }
    fclose(fp);

    struct doubleSymbol {
        char symbol;
        int repeat;
    };

    doubleSymbol repeats[128];

    int repeat_index = 0;
    text_index = 0;

    while (text_index < 2048) {
        if (text[text_index] != text[text_index+1]
            or isSpecial(text[text_index])
            or isSpecial(text[text_index+1])) {
            text_index++;
        } else {
            int inRepeatIndex = -1;
            for (int i = 0; i < repeat_index; i++) {
                if (repeats[i].symbol == text[text_index]) {
                    inRepeatIndex = i;
                    break;
                }
            }
            if (inRepeatIndex != -1) {
                repeats[inRepeatIndex].repeat++;
            } else {
                repeats[repeat_index].symbol = text[text_index];
                repeats[repeat_index].repeat = 1;
                repeat_index++;
            }
            text_index += 2;
        }
    }
    for (int i = 0; i < repeat_index; i++) {
        printf("%c %d\n", repeats[i].symbol, repeats[i].repeat);
    }

    return 0;
}

