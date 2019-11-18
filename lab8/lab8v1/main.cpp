#include <iostream>
using namespace std;

int main() {
    int a[30] = {0, 12, 3, 8, 8, 9, 0, 7, 19, 14, 11, 19, 20, 10, 18, 18, 11, 10, 18, 5, 10, 15, 11, 7, 10, 17, 20, 3, 1, 5};
    int b=0;
    unsigned long int c=1;
    for (int i=0; i<30; i++) {
        if (a[i]&1) {
            c *= a[i];
            b++;
        }
    }
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    return 0;
}