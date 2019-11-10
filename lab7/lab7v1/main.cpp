#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159265
#define G 9.81
#define target 10
#define target_size float(1)/2

int main() {
    int v, alpha;
    float l;
    cout << "Для завершения программы введите 0 как входное данное" << endl;
    while (true) {
        cout << "Введите скорость: ";
        cin >> v;
        cout << "Введите угол: ";
        cin >> alpha;
        if (alpha==0 or v==0) {
            cout << "Запрошен выход" << endl;
            return 0;
        }
        l = (pow(v, 2)*sin(2*float(alpha)*PI/180)/G);
        //cout << "L: " << l << endl;
        if ((l<target+target_size) and (l>target-target_size)) {
            cout << "Отличное попадание!" << endl;
            break;
        } else {
            cout << "Вы не попали :(" << endl;
        }
    }
    return 0;
}