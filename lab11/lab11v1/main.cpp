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
    for (auto & student : students) {
        if ((student.marks[0] > 3) and (student.marks[1] > 3) and (student.marks[2] > 3)) {
            printf("Name: %s\nBirthday: %d.%d\nMarks: %d,%d,%d\n\n",
                    student.name,
                    student.birth_month, student.birth_year,
                    student.marks[0], student.marks[1], student.marks[2]);
        }
    }
    return 0;
}
