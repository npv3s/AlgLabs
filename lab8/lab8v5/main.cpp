#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int a_len=12;
    srand(unsigned(time(0)));
    double k = double(4)/RAND_MAX;
    double a[a_len];
    double* index = a;
    for (int i=0; i<a_len; i++){
        *(index + i) = rand() * k - 2;
    }
    for (int i=0; i<a_len; i++){
        if (abs(a[i])<1) {
            for (int y=i; y<(a_len-1); y++) {
                a[y] = a[y+1];
            }
            a[a_len-1] = 0;
        }
    }
    // Magic array print
    for (const auto& e : a) {
        std::cout << e << std::endl;
    }
    return 0;
}