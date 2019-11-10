#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    cout << "Pi counter" << endl;
    long double pi_1 = 0, pi_2 = 0;
    for(unsigned int i = 0; i < 500000; i++) {
        pi_1 += (1/pow(16,i))*(double(4)/(8*i+1)-double(2)/(8*i+4)-double(1)/(8*i+5)-double(1)/(8*i+6));
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
