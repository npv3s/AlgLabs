#include <iostream>
#include "lib.h"
using namespace std;

int main(int argc, char* argv[]) {
    const int nums_len = atoi(argv[1]);
    if ((nums_len + 2) > argc) {
        cout << "Слишком мало цифр!" << endl;
        return 1;
    } if ((nums_len + 2) < argc) {
        cout << "Слишком много цифр!" << endl;
        return 1;
    }
    int nums[nums_len];
    for (int i = 2; i < (nums_len + 2); i++) {
        nums[i-2] = atoi(argv[i]);
    }
    cout << sum(nums_len, nums) << endl;
    return 0;
}
