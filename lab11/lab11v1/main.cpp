#include <cstdio>

int main() {
    struct student {
        char name[255];
        short int birth_month;
        int birth_year;
        int marks[3];
    } students[5];
    students[0] = {"Arcadiy", 9, 2002, {4, 4, 5}};
    students[1] = {"Sergey", 5, 2002, {5, 4, 5}};
    students[2] = {"Aleksandr", 5, 2003, {3, 5, 4}};
    students[3] = {"Dominator", 5, 2002, {3, 3, 5}};
    students[4] = {"Vlad", 10, 2003, {3, 5, 3}};
    for (auto & student : students) {
        if ((student.marks[0] > 3) and (student.marks[1] > 3) and (student.marks[2] > 3)) {
            printf("Name: %s\nBirthday: %d.%d\nMarks: %d,%d,%d\n",
                    student.name,
                    student.birth_month, student.birth_year,
                    student.marks[0], student.marks[0], student.marks[0]);
        }
    }
    return 0;
}
