#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    cout << "Pi counter" << endl;
    long double pi_1 = 0, pi_2 = 0;
    for (long long int i=0; i<50000000; i += 1) {
        pi_1 += double(4)/(1+4*i)-double(4)/(3+4*i);
        //cout << long(pi_1*10000000000) << " " << 31415926535 << endl;
        if (long(pi_1*10000000000) == 31415926535) {
            cout << pi_1 << endl;
            return 0;
        }
    }
    cout << "Pi: " << setprecision(11) << pi_1 << endl;
    cout << "Pi: " << setprecision(11) << pi_2 << endl;
    return 0;
}

строчка

call func



func:
    строчка
    ret