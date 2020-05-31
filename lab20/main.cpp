#include <iostream>
#include <cstdio>
#include <cstring>
#include "student.h"

using namespace std;

class Student {
    char *surname;
    char *name;
    char *patronymic;
    short int marks[3];
    char *dob;
    bool grants;
public:
    static int quantity;
    Student() {
        this->surname = nullptr;
        this->name = nullptr;
        this->patronymic = nullptr;
        *this->marks = 0;
        this->dob = nullptr;
        this->grants = false;
    }
    Student(char *surname, char *name, char *patronymic, short int marks[3], char *dob) {
        this->surname = new char[strlen(surname) + 1];
        this->name = new char[strlen(name) + 1];
        this->patronymic = new char[strlen(patronymic) + 1];
        strcpy(this->surname, surname);
        strcpy(this->name, name);
        strcpy(this->patronymic, patronymic);
        memcpy(this->marks, marks, sizeof(short int) * 3);
        this->dob = new char[strlen(dob) + 1];
        strcpy(this->dob, dob);
        Student::quantity++;
        this->grants = true;
        for (short mark : this->marks) {
            if (mark < 4) this->grants = false;
        }
    }

    ~Student() {
        if (this->name == nullptr) return;
        delete this->surname;
        delete this->name;
        delete this->patronymic;
        delete this->dob;
        this->name = nullptr;
    }

    Student &operator=(const Student &t) {
        if (this == &t) return *this;
        this->surname = t.surname;
        this->name = t.name;
        this->patronymic = t.patronymic;
        *this->marks = *t.marks;
        this->dob = t.dob;
        this->grants = t.grants;
        return *this;
    }

    Student copy() {
        Student n;
        n.surname = new char[strlen(this->surname) + 1];
        n.name = new char[strlen(this->name) + 1];
        n.patronymic = new char[strlen(this->patronymic) + 1];
        strcpy(n.surname, this->surname);
        strcpy(n.name, this->name);
        strcpy(n.patronymic, this->patronymic);
        memcpy(n.marks, this->marks, sizeof(short int) * 3);
        n.dob = new char[strlen(this->dob) + 1];
        strcpy(n.dob, this->dob);
        n.grants = this->grants;
        return n;
    }

    bool operator>(const Student &s) {
        if (this == &s) return false;
        char *name_1, *name_2;
        unsigned long size_1 = strlen(s.name) + strlen(s.surname) + strlen(s.patronymic) - 2;
        unsigned long size_2 = strlen(this->name) + strlen(this->surname) + strlen(this->patronymic) - 2;
        name_1 = new char[size_1];
        name_2 = new char[size_2];
        strcpy(name_1, s.name);
        strcpy(strchr(name_1, '\0'), s.surname);
        strcpy(strchr(name_1, '\0'), s.patronymic);
        strcpy(name_2, this->name);
        strcpy(strchr(name_2, '\0'), this->surname);
        strcpy(strchr(name_2, '\0'), this->patronymic);
        bool out = false;
        for (int i = 0; i < size_1 < size_2 ? size_1 : size_2; i++) {
            if (name_1[i] > name_2[i]) {
                out = true;
                break;
            }
        }
        return out;
    }

    void print() {
        cout << "Фамилия: " << this->surname << endl;
        cout << "Имя: " << this->name << endl;
        cout << "Отчество: " << this->patronymic << endl;
        cout << "Оценки: " << this->marks[0] << " " << this->marks[1] << " " << this->marks[2] << " " << endl;
        cout << "Наличие стипендии: ";
        if (this->grants) cout << "+";
        else cout << "-";
        cout << endl;
        cout << "Дата рождения: " << this->dob << endl;
    }
};

int Student::quantity = 0;

int main() {
    short int marks[3] = {3, 3, 3};
    Student Ivan("Ivanov", "Ivan", "Ivanovich", marks, "00.00.0000");
    //short int marks_2[3] = {5, 5, 5};
    //Student Danya("Golovachev", "Danila", "Andreevich", marks_2, "00.00.0000");
    Ivan.print();
    Student Ivan2 = Ivan.copy();
    Ivan2.print();
    //Danya.print();
    //Danya.~Student();
    return 0;
}
