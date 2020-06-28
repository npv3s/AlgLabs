#include <iostream>
#include <math.h>

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

int f1(int x) {
    int y = (int) pow(x, 2) + 3 * x + 5;
    return y;
}

int f2(int x) {
    int y = (1 / x) + 2 * x;
    return y;
}

void table_print(int (*f)(int), int x1, int x2, int shag) {
    for (int i = x1; i < x2; i += shag) {
        cout << f(i) << " ";
    }
    cout << endl;
}

int main() {
    int step, x1, x2, f;
    cout << "Введите шаг функции ";
    step = safe_int();
    cout << "Введите x1 ";
    x1 = safe_int();
    cout << "Введите x2 ";
    x2 = safe_int();
    cout << "f1=x^2+3x+5\nf2=1/x+2x" << endl;
    do {
        cout << "Какую функцию выполнить? (1/2)" << endl;
        f = safe_int();
        if (f == 1) table_print(f1, x1, x2, step);
        else if (f == 2) table_print(f2, x1, x2, step);
    } while (not(f == 1 or f ==2));
}

