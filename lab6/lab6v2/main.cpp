#include <cmath>
#include <iostream>
using namespace std;

int main() {
    float x, y;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    float rad = sqrt(abs(pow(x,2)+pow(y,2)));
    if (rad<=1) {
        cout << "2 очка" << endl;
    } else if (rad<=2) {
        cout << "1 очко" << endl;
    } else {
        cout << "0 очков" << endl;
    }
}