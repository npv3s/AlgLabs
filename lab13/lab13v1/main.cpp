#include <iostream>
#include <cmath>
using namespace std;

int distanceFromCenter(int x, int y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main() {
    int radius;
    cout << "Введите радиус: ";
    cin >> radius;
    //radius = 3;
    int x[] = {0, -3, 5, 3, -4, 5, 0, 4, 2, 4};
    int y[] = {3, -3, -5, 5, 0, -2, 4, -5, 1, 1};
    unsigned int sum = 0;
    for(int i = 0; i < 10; i++) {
        if (distanceFromCenter(x[i], y[i]) <= radius) {
            sum++;
        }
    }
    cout << "К-во точек в радиусе: " << sum << endl;
    return 0;
}
