#include <iostream>
#include "dynamic_array.h"
using namespace std;

int main() {
    short int todo;
    bool is_init = false;
    Node pbeg = Node{0, nullptr, nullptr};
    Node *pend = &pbeg;
    int val;
    while (true) {
        cout << "Выберите режим работы:\n"
                "1. Вывод списка\n"
                "2. Искать элемент\n"
                "3. Добавить элемент в конец\n"
                "4. Вставить элемент\n"
                "5. Выйти из программы\n";

        cin >> todo;
        switch (todo) {
            case 1:
                print(&pbeg);
                break;
            case 2:
                if (is_init) {
                    cout << "Введите искомое значение: ";
                    cin >> val;
                    Node *pf = find(&pbeg, val);
                    if (pf) cout << pf->d << endl;
                    else cout << "Не найдено!" << endl;
                } else {
                    cout << "Список пуст!" << endl;
                }
                break;
            case 3:
                cout << "Введите добавляемое значение: ";
                cin >> val;
                if (is_init) {
                    add(&pend, val);
                } else {
                    pbeg.d = val;
                    is_init = true;
                }
                break;
            case 4:
                cout << "Введите добавляемое значение: ";
                cin >> val;
                int key;
                cout << "Введите номер элемента: ";
                cin >> key;
                if (is_init) {
                    insert(&pbeg, &pend, val, key);
                } else {
                    pbeg.d = val;
                    is_init = true;
                }
                break;
            default:
            case 5:
                return 0;
        }
    }
}
