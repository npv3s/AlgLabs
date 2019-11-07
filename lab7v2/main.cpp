#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    cout << "Pi counter" << endl;
    double pi_1 = 0, pi_2 = 0;
    for (long long int i=0; i<1000000000; i += 2) {
        pi_1 += double(4)/(1+2*i)-double(4)/(3+2*i);
    }
    cout << "Pi: " << setprecision(11) << pi_1 << endl;
    cout << "Pi: " << setprecision(11) << pi_2 << endl;
    return 0;
}