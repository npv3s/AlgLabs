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
            {"Arkadiy",   9,  2002, {3, 3, 3}},
            {"Sergey",    5,  2002, {5, 4, 5}},
            {"Aleksandr", 5,  2003, {3, 5, 4}},
            {"Dominator", 5,  2002, {3, 3, 5}},
            {"Vlad",      10, 2003, {3, 5, 3}}};
    int threes[5];
    for (int i = 0; i < 5; i++) { threes[i] = count_3(students[i].marks); }
    bool is_sorted = false;
    while (!is_sorted) {
        is_sorted = true;
        for (int i = 0; i < 4; i++) {
            if (threes[i + 1] < threes[i]) {
                int tmp1 = threes[i];
                threes[i] = threes[i + 1];
                threes[i + 1] = tmp1;
                student tmp2 = students[i];
                students[i] = students[i + 1];
                students[i + 1] = tmp2;
                is_sorted = false;
            }
        }
    }
    for (auto &student : students) {
        printf("Name: %s\nBirthday: %d.%d\nMarks: %d,%d,%d\n\n",
               student.name,
               student.birth_month,
               student.birth_year,
               student.marks[0],
               student.marks[1],
               student.marks[2]);
    }
    return 0;
}
