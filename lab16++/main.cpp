#include <iostream>
#include <cstring>

using namespace std;

#define FILENAME "db.csv"
#define CODE_SIZE 10
#define NAME_SIZE 32

struct Item {
    char code[CODE_SIZE];
    char name[NAME_SIZE];
    int amount;
    int price;
};

Item to_item(const char *str) {
    Item out;
    int text_index = 0;
    memset(out.code, '\0', CODE_SIZE);
    for (; str[text_index] != ',' && text_index < CODE_SIZE; text_index++) {
        out.code[text_index] = str[text_index];
    }
    memset(out.name, '\0', NAME_SIZE);
    int local_index;
    for (local_index = 0, text_index++; str[text_index] != ',' && local_index < NAME_SIZE; text_index++, local_index++) {
        out.name[local_index] = str[text_index];
    }
    char amount_str[10] = {'\0'};
    for (local_index = 0, text_index++; str[text_index] != ',' && local_index < 10; text_index++, local_index++) {
        amount_str[local_index] = str[text_index];
    }
    out.amount = atoi(amount_str);
    char price_str[10] = {'\0'};
    for (local_index = 0, text_index++; str[text_index] != ',' && local_index < 10; text_index++, local_index++) {
        price_str[local_index] = str[text_index];
    }
    out.price = atoi(price_str);
    return out;
}

int main() {
    cout << "СТАРТУЕМ!" << endl;

    Item example = to_item("D000000001,Dress,100,1000");

    FILE *fp;
    if ((fp = fopen(FILENAME, "r")) == nullptr) {
        puts("Невозможно открыть файл");
        return -1;
    }

    int len = 1; // Последняя строка без '\n'
    char buff;
    while ((buff = getc(fp)) != EOF) {
        if (buff == '\n') len++;
    }
    fclose(fp);

    Item db[len];


    return 0;
}
