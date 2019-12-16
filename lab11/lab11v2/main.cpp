#include <cstdio>

bool p_surname(char name[255]) {
    int index = 0;
    for (int i = 0; i < 255; i++) {
        if (name[i] == ' ') {
            index = i;
            break;
        }
    }
    bool out = false;
    for (; index < 255; index++) {
        if (name[index] == 'P' or name[index] == 'p') {
            out = true;
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
            {"Arkadiy Petrov", 9, 2002, {4, 4, 5}},
            {"Sergey Sokolov", 5, 2002, {5, 4, 5}},
            {"Aleksandr Ivanov", 5, 2003, {3, 5, 4}},
            {"Pavel Smirnov", 5, 2002, {3, 3, 5}},
            {"Vlad Popov", 10, 2003, {3, 5, 3}}};
    for (auto & student : students) {
        if (p_surname(student.name)) {
            printf("Name: %s\nBirthday: %d.%d\nMarks: %d,%d,%d\n\n",
                   student.name,
                   student.birth_month, student.birth_year,
                   student.marks[0], student.marks[1], student.marks[2]);
        }
    }
    return 0;
}