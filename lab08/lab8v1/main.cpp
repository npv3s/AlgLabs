#include <ctime>
#include <iostream>
using namespace std;

int main() {
    srand(unsigned(time(0)));
    double k = double(100)/RAND_MAX;
    int a[100];
    int* index = a;
    for (int i=0; i<100; i++){
        *(index + i) = rand() * k;
    }

    index = a;
    int b=0;
    unsigned long int c=1;
    for (int i=0; i<100; i++) {
        if (*(index + i)&1) {
            c *= *(index + i);
            b++;
        }
    }
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    return 0;
}