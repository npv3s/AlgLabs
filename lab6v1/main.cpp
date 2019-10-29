#include <iostream>
using namespace std;

int main() {
    int x, y;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    if (x==0 and y==0) {
        cout << "Начало координат" << endl;
        return 0;
    }
    if (x==0) {
        cout << "Точка лежит на оси х" << endl;
        return 0;
    }
    if (y==0) {
        cout << "Точка лежит на оси y" << endl;
        return 0;
    }
    int cases;
    cases = 2*(x>0)+(y>0);
    switch (cases) {
        case 3:
            cout << "I четверть" << endl;
            break;
        case 1:
            cout << "II четверть" << endl;
            break;
        case 0:
            cout << "III четверть" << endl;
            break;
        case 2:
            cout << "IV четверть" << endl;
            break;
    }
    return 0;
}