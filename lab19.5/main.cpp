#include <iostream>
using namespace std;

class one {
public:
    int sample = 5; // 1
    int func(int sample) { // 2
        return ++sample;
    }
};

namespace two {
    int sample() { // 3
        return 5;
    }

    int sample(int sample) {  // 4 5
        return ++sample;
    }
}

class three {
    int sample = 6; // 6
    int func(int sample) { // 7
        return ++sample;
    }
};

int main() {
    one sample; // 8
    cout << sample.func(sample.sample) << endl;
    for (int sample = 0; sample < 5; sample++) // 9
        cout << "Hello" << endl;
    return 0;
}