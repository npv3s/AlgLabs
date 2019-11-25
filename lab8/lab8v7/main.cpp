#include <iostream>

int main() {
    int a_len=20;
    int a[a_len];
    for (int i=0; i<a_len; i++){
        a[i] = i;
    }

    a_len /= 2;
    for (int i=1; i<a_len; i++) {
        int tmp = a[i];
        int y;
        for(y=i; y<a_len; y++) {
            a[y] = a[y+1];
        }
        a[a_len-1] = a[a_len-1+i];
        a[a_len-1+i] = tmp;

    }

    for (const auto& e : a) {
        std::cout << e << std::endl;
    }

    return 0;
}