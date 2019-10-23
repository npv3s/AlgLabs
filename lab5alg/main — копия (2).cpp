#include <iostream>
using namespace std;

int main() {
    short int a = 16;
    cout << "a: " << a << endl;

    cout << "a<<5: " << (a<<5) << endl;
    cout << "a*2^5: " << a*32 << endl;

    cout << "a>>3: " << (a>>3) << endl;
    cout << "a/(2^3): " << a/8 << endl << endl;

    short int b = 80;
    cout << "b: " << b << endl;

    cout << "b<<6: " << (b<<6) << endl;
    cout << "b*2^6: " << b*64 << endl;

    cout << "b>>4: " << (b>>4) << endl;
    cout << "b/(2^4): " << b/16 << endl << endl;

    int c = 3, d = 4;
    cout << "c: " << c << ", d: " << d << endl;

    if (c&1) {cout << "c нечётное!" << endl;}
    else {cout << "c чётное!" << endl;}

    if (d&1) {cout << "d нечётное!" << endl;}
    else {cout << "d чётное!" << endl;}
}