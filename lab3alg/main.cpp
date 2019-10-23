#include <iostream>
using namespace std;

int main() {
    int a;
    float b;
    char c;
    cout << "Введите a (int): ";
    cin >> a;
    cout << "Введите b (float): ";
    cin >> b;
    cout << "Введите c (char): ";
    cin >> c;
    int unsigned u;
    u = -a;
    cout << "unsigned -a: " << u << endl;
    cout << "c as int: " << int(c) << endl;
    cout << "a/0.3: " << a / 0.3 << endl;
    cout << "a*2: " << a * 2 << endl;
    cout << "11/a: " << 11 / a << endl;
    cout << "11%a: " << 11 % a << endl;
    cout << "b/0.333: " << b / 0.333 << endl;
    cout << "a: " << a << endl;
    cout << "a++: " << a++ << endl;
    cout << "++a: " << ++a << endl;
    cout << "a>b: " << (a > b) << endl;
    cout << "a<b: " << (a < b) << endl;
    cout << "a>=b: " << (a >= b) << endl;
    cout << "!a: " << (!a) << endl;
    cout << "a&&b: " << (a && b) << endl;
    cout << "a||b: " << (a || b) << endl;

    cout << "3/2: " << float(3)/float(2) << endl;
    cout << "3/2: " << int(3)/int(2) << endl;

    cout << "b: " << ((b>0)?b:-b) << endl;

    int a1 = 2, b1 = 3, c1 = 1;
    c1+=a1>0 && b1 <= a1 ? a1++ + b1 : a1-- - b1, a1 + b1;
    cout << "c: " << c1;
    return 0;
}