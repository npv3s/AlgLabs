#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

#define z_start 2
#define z_end 4

int main() {
    // Весна
    float y;
    cout << "y          x   z" << left << endl;
    for (float x=0; x<1.1; x += 0.1) {
        for (float z=z_start; z<=z_end; z++) {
            y = (sqrt(pow(x, 2)+pow(x, 2))/(x+z-3))*cos(x);
            if (isnan(y) or isinf(y)) {
                continue;
            }
            cout << setw(10) << y << " " << setw(3) << x << " " << setw(3) << z << endl;
        }
    }

    return 0;
}