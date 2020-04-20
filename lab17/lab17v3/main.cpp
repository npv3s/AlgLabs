#include <iostream>

using namespace std;

struct Node {
    int d;
    Node *next;
    Node *prev;
};

Node *first(int d) {
    Node *pv = new Node;
    pv->d = d;
    pv->next = nullptr;
    pv->prev = nullptr;
    return pv;
}

void add(Node **pend, int d) {
    Node *pv = new Node;
    pv->d = d;
    pv->next = nullptr;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}

Node *find(Node *const pbeg, int key) {
    Node *pv = pbeg;
    while (pv) {
        if (pv->d == key) break;
        pv = pv->next;
    }
    return pv;
}

bool remove(Node **pbeg, Node **pend, int key) {
    if (Node *pkey = find(*pbeg, key)) {
        if (pkey == *pbeg) {
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = nullptr;
        } else if (pkey == *pend) {
            *pend = (*pend)->prev;
            (*pend)->next = nullptr;
        } else {
            (pkey->prev)->next = pkey->next;
            (pkey->next)->prev = pkey->prev;
        }
        delete pkey;
        return true;
    }
    return false;
}

Node *insert(Node *const pbeg, Node **pend, int key, int d) {
    if (Node *pkey = find(pbeg, key)) {
        Node *pv = new Node;
        pv->d = d;
        pv->next = pkey->next;
        pv->prev = pkey;
        pkey->next = pv;
        if (pkey != *pend)
            (pv->next)->prev = pv;
        else
            *pend = pv;
        return pv;
    }
    return nullptr;
}


int main() {
    short int todo;
    bool is_init = false;
    Node *pbeg = nullptr;
    Node *pend = nullptr;
    int val;
    while (true) {
        cout << "Выберите режим работы:\n"
                "1. Вывод списка\n"
                "2. Искать элемент\n"
                "3. Добавить элемент в конец\n"
                "4. Вставить элемент\n"
                "5. Выйти из программы\n";

        cin >> todo;
        if (todo == 1) {
            break;
        }
        if (todo == 2) {
            if (is_init) {
                cout << "Введите искомое значение: ";
                cin >> val;
                Node *pf = find(pbeg, val);
                if (pf) cout << pf->d << endl;
                else cout << "Не найдено!" << endl;
            } else {
                cout << "Список пуст!" << endl;
            }
        }
        if (todo == 3) {
            cout << "Введите добавляемое значение: ";
            cin >> val;
            if (is_init) {
                add(&pend, val);
            } else {
                delete pbeg;
                delete pend;
                Node *pbeg = first(val);
                Node *pend = pbeg;
                is_init = true;
            }
        }
        if (todo == 4) {
            cout << "Введите добавляемое значение: ";
            cin >> val;
            int key;
            cout << "Введите номер элемента: ";
            cin >> key;
            if (is_init) {
                insert(pbeg, &pend, val, key);
            } else {
                delete pbeg;
                delete pend;
                Node *pbeg = first(val);
                Node *pend = pbeg;
                is_init = true;
            }
        } else {
            return 0;
        }
    }
    return 0;
}
