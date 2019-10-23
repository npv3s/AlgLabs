#include <iostream>
#include <bitset>
using namespace std;

int main() {
    short int a = 255;
    cout << bitset<16>(a) << std::endl;
    short int b = -4081;
    cout << bitset<16>(b) << std::endl;
    short int c = 170;
    cout << bitset<16>(c) << std::endl;

    cout << (short int)(a&b) << endl;
    cout << '(' << bitset<16>(a&b) << ')' << endl;
    cout << (short int)(a|c) << endl;
    cout << '(' << bitset<16>(a|c) << ')' << endl;
    cout << (short int)(a^c) << endl;
    cout << '(' << bitset<16>(a^c) << ')' << endl;
    cout << (short int)(~b) << endl;
    cout << '(' << bitset<16>(~b) << ')' << endl;
    cout << (short int)(a<<15) << endl;
    cout << '(' << bitset<16>(a<<15) << ')' << endl;
    cout << (short int)(a>>3) << endl;
    cout << '(' << bitset<16>(a>>3) << ')' << endl;
    return 0;
}