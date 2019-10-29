#include <iostream>
using namespace std;

int main() {
    float x, y;
    char todo;
    cout << "Введите x: ";
    cin >> x;
    cout << "Действие: ";
    cin >> todo;
    cout << "Введите y: ";
    cin >> y;
    switch (todo) {
        case '+':
            cout << x+y << endl;
            break;
        case '-':
            cout << x-y << endl;
            break;
        case '/':
            cout << x/y << endl;
            break;
        case '*':
            cout << x*y << endl;
            break;
    }
    return 0;
}