#include <cstdio>

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
    float middle[5];
    for (int i = 0; i < 5; i++) {
        middle[i] = float(students[i].marks[0] + students[i].marks[1] + students[i].marks[2])/3;
    }
    short int max = 0;
    for (int i = 1; i < 5; i++) {
        if (middle[max] < middle[i]) { max = i; }
    }
    printf("Name: %s\nBirthday: %d.%d\nMarks: %d,%d,%d\n\n",
           students[max].name,
           students[max].birth_month, students[max].birth_year,
           students[max].marks[0], students[max].marks[1], students[max].marks[2]);
    return 0;
}
