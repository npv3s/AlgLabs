#include <iostream>
#include <cstdio>
#include <cstring>
#include "student.h"
using namespace std;

struct FIO {
    char *surname;
    char *name;
    char *patronymic;
};

class Student {
    FIO *name;
    short int marks[3];
    char *dob;
    bool grants;
public:
    static int quantity;
    Student(char *surname, char *name, char *patronymic, short int marks[3], char *dob) {
        FIO fio{};
        fio.surname = new char[strlen(surname) + 1];
        fio.name = new char[strlen(name) + 1];
        fio.patronymic = new char[strlen(patronymic) + 1];
        strcpy(fio.surname, surname);
        strcpy(fio.name, name);
        strcpy(fio.patronymic, patronymic);
        this->name = FIO{surname, name, patronymic};
        memcpy(this->marks, marks, sizeof(short int)*3);
        this->dob = new char[strlen(dob) + 1];
        strcpy(this->dob, dob);
        Student::quantity++;
        this->grants = true;
        for (short mark : this->marks) {
            if (mark < 4) this->grants = false;
        }
    }
    ~Student() {
        delete this->name.surname;
        //delete this->name.name;
        //delete this->name.patronymic;
        //delete[] &this->marks;
        //delete &this->grants;
        delete this->dob;
    }
    bool operator >(const Student &s) {
        if (this == &s) return false;
        char *name_1, *name_2;
        unsigned long size_1 = strlen(s.name.name) + strlen(s.name.surname) + strlen(s.name.patronymic) - 2;
        unsigned long size_2 = strlen(this->name.name) + strlen(this->name.surname) + strlen(this->name.patronymic) - 2;
        name_1 = new char[size_1];
        name_2 = new char[size_2];
        strcpy(name_1, s.name.name);
        strcpy(strchr(name_1, '\0'), s.name.surname);
        strcpy(strchr(name_1, '\0'), s.name.patronymic);
        strcpy(name_2, this->name.name);
        strcpy(strchr(name_2, '\0'), this->name.surname);
        strcpy(strchr(name_2, '\0'), this->name.patronymic);
        bool out = false;
        for (int i = 0; i < size_1<size_2?size_1:size_2; i++) {
            if (name_1[i] > name_2[i]) {
                out = true;
                break;
            }
        }
        return out;
    }

    void print() {
        cout << "Фамилия: " << this->name.surname << endl;
        cout << "Имя: " << this->name.name << endl;
        cout << "Отчество: " << this->name.patronymic << endl;
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
    short int marks_2[3] = {5, 5, 5};
    Student Danya("Golovachev", "Danila", "Andreevich", marks_2, "00.00.0000");
    Ivan.print();
    Danya.print();
    Danya > Ivan;
    return 0;
}
