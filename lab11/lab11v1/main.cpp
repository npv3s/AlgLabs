#include <cstdio>

bool more_3(int marks[3]) {
    bool out = true;
    for (int i = 0; i < 3; i++) {
        if (marks[i] < 4) {
            out = false;
            break;
        }
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
    for (auto & student : students) {
        if (more_3(student.marks)) {
            printf("Name: %s\nBirthday: %d.%d\nMarks: %d,%d,%d\n\n",
                    student.name,
                    student.birth_month, student.birth_year,
                    student.marks[0], student.marks[1], student.marks[2]);
        }
    }
    return 0;
}
