#include <iostream>

using namespace std;

int safe_int() {
    int x;
    cin >> x;
    if (cin.fail() != 0) return x;
    while (cin.fail() == 1) {
        cout << "Введите число!" << endl;
        cin.clear();
        cin.sync();
        cin >> x;
    }
    return x;
}

int test() {
    int mode, ans, user_ans;
    int a = rand() % 100;
    int b = rand() % 100;
    cout << "Выберете тип вопроса: (1 - вычитание, 2 - сложение)" << endl;
    cin >> mode;
    switch (mode) {
        case 1:
            ans = a - b;
            cout << a << " - " << b << " = ?" << endl;
            break;
        case 2:
            ans = a + b;
            cout << a << " + " << b << " = ?" << endl;
            break;
        default:
            cout << "Ответ не верный!" << endl;
    }
    int k = 3;
    for (;;) {
        if (k == 0) return 0;
        cout << "Введите ответ: " << endl;
        user_ans = safe_int();
        if (user_ans == ans) return k;
        else {
            k--;
            cout << "Ответ не верный!" << endl;
        }
    }
}

int main() {
    int mark = 0;
    for (int i = 0; i < 10; i++) {
        mark += test();
    }
    cout << "Ваш балл: " << endl;
    if (mark > 25) cout << 5 << endl;
    else if (mark > 20) cout << 4 << endl;
    else if (mark > 15) cout << 3 << endl;
    else cout << 2 << endl;
}