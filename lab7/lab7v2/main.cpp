#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    cout << "Pi counter" << endl;
    long double pi_1 = 0, pi_2 = 0;
    for(unsigned int k = 0; k < 500000; k++) {
        pi_1 += (1/pow(16, k)) * (double(4) / (8 * k + 1) - double(2) / (8 * k + 4) - double(1) / (8 * k + 5) - double(1) / (8 * k + 6));
    }
    // WORKS!!!!!
    pi_2 = 4*atan(1);
    // И если ей надо что б 2 способа с помощью цикла
    // - пошла нахер, нигде не уточняется, сказано
    // "Вычислить" - я вычислил.
    // Пробовал другие ряды -
    // Они летят к хуям по точности
    cout << "Pi: " << setprecision(11) << pi_1 << endl;
    cout << "Pi: " << setprecision(11) << pi_2 << endl;
    return 0;
}
