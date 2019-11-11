#include <iostream>
#include <string>
#include <cmath>

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
    base_2 = base_1*2;
    float offset = float(base_1)/2/float(height-1);
    cout << offset << endl;
    int start = base_1/2;
    int end = base_2-start;
    cout << fill(start, " ") << fill(base_1, "*") << endl;
    for (int i=1; i<(height-1); i++) {
        int left = start-round(offset*float(i));
        int right = end+round(offset*float(i));
        cout << fill(left, " ") << fill (right-left, "*") << endl;
    }
    cout << fill(base_2, "*") << endl;

    return 0;
}