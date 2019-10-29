#include <iostream>
using namespace std;

int main() {
    float x, y;
    char todo;
    cout << "Введите x: " << endl;
    cin >> x;
    cout << "Действие: " << endl;
    cin >> todo;
    cout << "Введите y: " << endl;
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