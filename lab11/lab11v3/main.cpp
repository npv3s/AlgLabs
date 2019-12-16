#include <cstdio>

int count_3(int marks[3]) {
    int out = 0;
    for (int i = 0; i < 3; i++) {
        if (marks[i] == 3) { out++; }
    }
    return out;
}

int main() {
    struct student {
        char name[255];
        short int birth_month;
        int birth_year;
        int marks[3];
    } students[5] = {
            {"Arkadiy", 9, 2002, {4, 4, 5}},
            {"Sergey", 5, 2002, {5, 4, 5}},
            {"Aleksandr", 5, 2003, {3, 5, 4}},
            {"Dominator", 5, 2002, {3, 3, 5}},
            {"Vlad", 10, 2003, {3, 5, 3}}};
    short int threes[5];
    for (int i = 0; i < 5; i++) { threes[i] = count_3(students[i].marks); }
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 5; y++) {
            if (threes[y] == i) {
                printf("Name: %s\nBirthday: %d.%d\nMarks: %d,%d,%d\n\n",
                       students[y].name,
                       students[y].birth_month, students[y].birth_year,
                       students[y].marks[0], students[y].marks[1], students[y].marks[2]);
            }
        }
    }
    return 0;
}
