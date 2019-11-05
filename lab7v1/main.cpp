#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159265
#define G 9.81
#define target 10
#define target_size 1/2

int main() {
    int v, alpha;
    float l;
    while (true) {
        cout << "Введите скорость: ";
        cin >> v;
        cout << "Введите угол: ";
        cin >> alpha;
        l = (pow(v, 2)*sin(2*float(alpha)*PI/180)/G);
        cout << "L: " << l << endl;
        if ((l<target+target_size) or (l>target-target_size)) {
            break;
        }
    }
    return 0;
}