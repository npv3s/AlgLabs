#include <iostream>
#include "b_tree.h"

using namespace std;

int main() {
    int mode;
    Node *root = nullptr;
    while (true) {
        cout << "Выберете режим работы:\n"
                "1. Новая пара слов\n"
                "2. Перевести слово\n"
                "3. Представление словаря по к-ву запросов\n"
                "4. Вывод словарей\n"
                "5. Выход из программы\n";
        cin >> mode;
        if (mode == 5) return 0;
        switch (mode) {
            case 1:
                Word inp;
                inp.counter = 0;
                cout << "Введите английское слово: ";
                cin >> inp.eng;
                cout << "Введите русский перевод: ";
                cin >> inp.rus;
                if (root != nullptr) {
                    search_insert(root, inp, false);
                } else {
                    root = first(inp);
                }
                break;
            case 2:
                char word[WORD_SIZE];
                cout << "Введите английское слово: ";
                cin >> word;


            default:
                cout << "Это не число от 1 до 5!" << endl;
        }
    }
}
