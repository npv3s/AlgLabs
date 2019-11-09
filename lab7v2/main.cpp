#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    cout << "Pi counter" << endl;
    long double pi_1 = 1, pi_2 = 0;
    // todo pi_1
    // ...
    // WORKS!!!!!
    unsigned int val_2 = 1;
    for (double i=0; i<10000; i++) {
        pi_2 += double(1)/(val_2);
        val_2 += 2;
        pi_2 -= double(1)/(val_2);
        val_2 += 2;
    }
    cout << "Pi: " << setprecision(11) << pi_1 << endl;
    cout << "Pi: " << setprecision(11) << pi_2*4 << endl;
    return 0;
}
