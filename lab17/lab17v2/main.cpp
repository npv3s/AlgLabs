#include <iostream>
using namespace std;

int main() {
    for (int i = 0;; i++) {
        int *p = (int*)malloc(1024);
        cout << i << endl;
    }
    return 0;
}
