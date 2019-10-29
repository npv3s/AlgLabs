#include <cmath>
#include <iostream>
using namespace std;

int main() {
    float x, z;
    double y;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите z: ";
    cin >> z;
    if (z>0 and x<0) {
        y = pow(M_E, z) - 3*z + 5*pow(x,2);
    }
    if (z<0 and x>0) {
        y = x/z + pow(M_E, -x) + 4;
    }
    if (x==0 and z==0) {
        y = pow(0.589, pow(10, -4));
    }
    cout << "y = " << y << endl;

}