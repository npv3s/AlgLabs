#include <iostream>

int fast_overflow(long long int d) {
    return fast_overflow(d+1);
}

int slow_overflow(int d) {
    std::cout << d << std::endl;
    return slow_overflow(d+1);
}

int main() {
    std::cout << slow_overflow(0) << std::endl;
    return 0;
}
