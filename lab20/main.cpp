#include <iostream>
#include <cstring>

using namespace std;

#define loop while (true)
#define VEC_BLOCK_SIZE 10
#define VEC_TYPE Student
#define BUFF_SIZE 256

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
        this->grants = this->recount();
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
        unsigned long size_1 = strlen(s.surname) + strlen(s.name) + strlen(s.patronymic) - 2;
        unsigned long size_2 = strlen(this->surname) + strlen(this->name) + strlen(this->patronymic) - 2;
        name_1 = new char[size_1];
        name_2 = new char[size_2];
        strcpy(name_1, s.surname);
        strcpy(strchr(name_1, '\0'), s.name);
        strcpy(strchr(name_1, '\0'), s.patronymic);
        strcpy(name_2, this->surname);
        strcpy(strchr(name_2, '\0'), this->name);
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

    bool recount() {
        return this->grants = (marks[0] + marks[1] + marks[2]) / 3 > 4;
    }

    void print() {
        cout << "ФИО: " << this->surname << " " << this->name << " " << this->patronymic << endl;
        cout << "Оценки: " << this->marks[0] << " " << this->marks[1] << " " << this->marks[2] << " " << endl;
        cout << "Наличие стипендии: ";
        if (this->grants) cout << "+";
        else cout << "-";
        cout << endl;
        cout << "Дата рождения: " << this->dob << endl;
    }
};

int Student::quantity = 0;

class Vector {
    VEC_TYPE **vec;
    int size;
    int capacity;
public:
    Vector() {
        vec = new class VEC_TYPE *[VEC_BLOCK_SIZE];
        size = 0;
        capacity = VEC_BLOCK_SIZE;
    }

    ~Vector() {
        delete[] this->vec;
    }

    int len() {
        return this->size;
    }

    void append(VEC_TYPE *element) {
        if (size >= capacity) {
            VEC_TYPE **tmp = new class VEC_TYPE *[this->size];
            memcpy(tmp, this->vec, sizeof(VEC_TYPE *) * this->size);
            this->vec = new class VEC_TYPE *[this->size + VEC_BLOCK_SIZE];
            memcpy(this->vec, tmp, sizeof(VEC_TYPE *) * this->size);
            delete[] tmp;
            capacity += VEC_BLOCK_SIZE;
        }
        this->vec[size++] = element;
    }

    VEC_TYPE *get(int index) {
        return this->vec[index];
    }

    void pop() {
        if (size == 0) {
            cout << "Нельзя удалить ничего!" << endl;
            return;
        }
        if ((capacity - size) % VEC_BLOCK_SIZE == 0) {
            VEC_TYPE **tmp = new class VEC_TYPE *[this->size - VEC_BLOCK_SIZE];
            memcpy(tmp, this->vec, sizeof(VEC_TYPE *) * this->size - VEC_BLOCK_SIZE);
            delete[] this->vec;
            this->vec = tmp;
            capacity -= VEC_BLOCK_SIZE;
        }
        this->vec[--size] = nullptr;
    }

    int search(Student *element) {
        for (int i = 0; i < this->size; i++) {
            if (vec[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void sort() {
        bool is_sorted = false;
        while (!is_sorted) {
            is_sorted = true;
            for (int i = 0; i < this->size - 1; i++) {
                if (this->vec[i] < this->vec[i + 1]) {
                    is_sorted = false;
                    VEC_TYPE *tmp = this->vec[i];
                    this->vec[i] = this->vec[i + 1];
                    this->vec[i + 1] = tmp;
                }
            }
        }
    }
};

struct Buffer {
    char surname[BUFF_SIZE];
    char name[BUFF_SIZE];
    char patronymic[BUFF_SIZE];
    short int marks[3];
    char dob[BUFF_SIZE];
};

int main() {
    Vector vec;
    char mode;
    loop {
        cout << "1. Ввести нового студента\n"
                "2. Вывести всех студентов\n"
                "3. Удалить последнего студента\n"
                "4. Сортировать список студентов\n"
                "5. Выйти из программы\n"
                "Выберете режим работы: ";
        cin >> mode;
        switch (mode) {
            case '1': {
                Buffer buff{};
                cout << "Введите фамилию: " << endl;
                cin >> buff.surname;
                cout << "Введите имя: " << endl;
                cin >> buff.name;
                cout << "Введите отчество: " << endl;
                cin >> buff.patronymic;
                cout << "Введите дату рождения в формате DD.MM.YYYY: " << endl;
                cin >> buff.dob;
                cout << "Введите первую оценку: " << endl;
                cin >> buff.marks[0];
                cout << "Введите вторую оценку: " << endl;
                cin >> buff.marks[1];
                cout << "Введите третью оценку: " << endl;
                cin >> buff.marks[2];
                auto *tmp = new Student(buff.surname, buff.name, buff.patronymic, buff.marks, buff.dob);
                vec.append(tmp);
                break;
            }
            case '2':
                for (int i = 0; i < vec.len(); i++) vec.get(i)->print();
                break;
            case '3':
                vec.pop();
                break;
            case '4':
                vec.sort();
                break;
            case '5':
                return 0;
            default:
                cout << "Это не 1, не 2, не 3, не 4 и даже не 5" << endl;
        }

    }
}
