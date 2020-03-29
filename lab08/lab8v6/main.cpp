#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int a_len=30;
    srand(unsigned(time(0)));
    double k = double(200)/RAND_MAX;
    int a[a_len];
    for (int i=0; i<a_len; i++){
        a[i] = rand() * k - 100;
    }

    int r[30];
    int index = 0;
    for (int i=0; i<a_len; i++) {
        if (a[i] >= 0) {
            r[index] = a[i];
            index++;
        }
    }
    for (int i=0; i<a_len; i++) {
        if (a[i] < 0) {
            r[index] = a[i];
            index++;
        }
    }

    for (const auto& e : r) {
        std::cout << e << std::endl;
    }

    return 0;
}