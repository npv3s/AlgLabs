#include <iostream>
#include "b_tree.h"

using namespace std;

int main() {
    int mode;
    Node *root = nullptr;
    Node *root2 = nullptr;
    /*root = first("Car", "Машина");
    search_insert(root, "Apple", "Яблоко", 0, false);
    search_insert(root, "Year", "Год", 0, false);
    search_insert(root, "Time", "Время", 0, false);
    search_insert(root, "Man", "Человек", 0, false);
    search_insert(root, "Duck", "Утка", 0, false);
    print_tree(root, 1);
    for (int i = 0; i < 5; i++)
        cout << get_world(root, "Duck") << endl;
    for (int i = 0; i < 4; i++)
        cout << get_world(root, "Man") << endl;
    for (int i = 0; i < 3; i++)
        cout << get_world(root, "Time") << endl;
    for (int i = 0; i < 2; i++)
        cout << get_world(root, "Apple") << endl;
    cout << get_world(root, "Car") << endl;
    print_tree(root, 1);
    cout << "------------------" << endl;
    delete_tree(root2);
    root2 = nullptr;
    root2 = rebuild_tree(root, root2);
    print_tree(root2, 1);
    delete_tree(root2);
    root2 = nullptr;
    root2 = rebuild_tree(root, root2);
    print_tree(root2, 1);
*/
    while (true) {
        cout << "Выберете режим работы:\n"
                "1. Новая пара слов\n"
                "2. Перевести слово\n"
                "3. Представление словаря по к-ву запросов\n"
                "4. Вывод словаря\n"
                "5. Выход из программы\n";
        cin >> mode;
        if (mode == 5) return 0;
        switch (mode) {
            case 1: {
                char tmp1[256], tmp2[256];
                cout << "Введите английское слово: ";
                cin >> tmp1;
                cout << "Введите русский перевод: ";
                cin >> tmp2;
                if (root != nullptr)
                    search_insert(root, tmp1, tmp2, false);
                else
                    root = first(tmp1, tmp2);
            }
                break;
            case 2:
                char word[256];
                cout << "Введите английское слово: ";
                cin >> word;
                cout << get_world(root, word) << endl;
                break;
            case 3: {
                delete_tree(root2);
                root2 = nullptr;
                root2 = rebuild_tree(root, root2);
                print_tree(root2, 1);
                break;
            }
            case 4:
                print_tree(root, 1);
                cout << "-----------" << endl;
                print_tree(root2, 1);
                break;
            default:
                cout << "Это не число от 1 до 5!" << endl;
        }
    }
}
