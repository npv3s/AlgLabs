#include <iostream>
#include <string>
using namespace std;

string fill(int val, string chr) {
    string fill_str = "";
    for (int i=0; i<val; i++) {
        fill_str += chr;
    }
    return fill_str;
}

int main() {
    int height, base_1, base_2;
    cout << "Введите высоту трапеции: ";
    cin >> height;
    cout << "Введите верхнее основание трапеции: ";
    cin >> base_1;
    base_2 = base_1*1.5;
    float offset = base_2-base_1;
    offset /= height;
    cout << fill(base_1, "_") << endl;
    for (int i=1; i<(height+1); i++) {
        string raw = "|" + fill(base_2-1, " ");
        raw[base_1-1+i*offset] = '\\';
        cout << raw << endl;
    }
    cout << fill(base_2, "\u203E") << endl;

    return 0;
}