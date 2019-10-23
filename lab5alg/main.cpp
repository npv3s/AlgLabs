#include <iostream>
#include <cmath>
using namespace std;

bool select(int a, int index) {
    return bool(a&(1<<index));
}

int main() {
    short int a;
    short int b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    short int sum = 0;
    bool p0 = 0;
    int i;
    for (i=0; i<16; i++) {
        bool ai = select(a, i);
        bool bi = select(b, i);
        bool p = 0;
        if ((ai&bi)|((ai|bi)&p0)) {
            p = 1;
        }
        if (((ai+bi+p0)==1)|(ai&bi&p0)) {
            sum += pow(2, i);
        }
        p0 = p;
    }
    cout << sum;
}