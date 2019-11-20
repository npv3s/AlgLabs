#include <iostream>

int main() {
    int a_len=20;
    int a[a_len];
    for (int i=0; i<a_len; i++){
        a[i] = i;
    }

    int r[a_len];
    int index = 0;
    for (int i=0; i<a_len; i+=2) {
        r[index] = a[i];
        index++;
    }
    for (int i=1; i<a_len; i+=2) {
        r[index] = a[i];
        index++;
    }

    for (const auto& e : r) {
        std::cout << e << std::endl;
    }

    return 0;
}