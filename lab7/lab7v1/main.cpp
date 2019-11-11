#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159265
#define G 9.81
#define target 10
#define target_size float(1)/2

int main() {
    int v;
    float l, alpha;
    cout << "Для завершения программы введите 0 как входное данное" << endl;
    while (true) {
        cout << "Введите скорость: ";
        cin >> v;
        cout << "Введите угол: ";
        cin >> alpha;
        if (alpha==0 or v==0) {
            cout << "Запрошен выход" << endl;
            break;
        }
        alpha *= PI/180;
        float y = 0.001, x = 0, t = 0, prev_x;
        while (y >= 0) {
            y = v*sin(alpha)*t-(G*pow(t, 2))/2;
            prev_x = x;
            x = v*cos(alpha)*t;
            t += 0.01;
        }
        l = prev_x;
        //l = (pow(v, 2)*sin(2*double(alpha)*PI/180)/G);
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