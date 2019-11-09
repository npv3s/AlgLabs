#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    cout << "Pi counter" << endl;
    long double pi_1 = 1, pi_2 = 0;
    for (double i=0; i<0; i += 1) {
        if (i&&1) {
            pi_1 -= double(1)/((3+2*i)*pow(3, i+1));
        } else {
            pi_1 += double(1)/((3+2*i)*pow(3, i+1));
        }
        if (pi_1 >= 3.1415926535/pow(12, 0.5)) {
            cout << pi_1*pow(12, 0.5) << endl;
            cout << i << endl;
            return 0;
        }
    }
    // WORKS!!!!!
    unsigned int val_2 = 1;
    for (double i; i<10000; i++) {
        pi_2 += double(1)/(val_2);
        val_2 += 2;
        pi_2 -= double(1)/(val_2);
        val_2 += 2;
    }
    cout << "Pi: " << setprecision(11) << pi_1*pow(12, 0.5) << endl;
    cout << "Pi: " << setprecision(11) << pi_2*4 << endl;
    return 0;
}
