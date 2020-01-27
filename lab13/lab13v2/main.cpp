#include <iostream>

bool toCall(int a) {
    return a >= 0 and a <= 1;
}

int matrixProcessing(const int *matrix, int height, int width) {
    int sum = 0;
    for (int i = 0; i < height; i++) {
        for (int y = 0; y < width; y++) {
            if (toCall(*(matrix + i * height + y))) {
                sum++;
            }
        }
    }
    return sum;
}

int main() {
    int x[5][5] = {{3, 1, 1, 1, 1},
                   {0, 3, 0, 2, 0},
                   {3, 0, 1, 2, 0},
                   {0, 3, 2, 0, 0},
                   {0, 1, 2, 1, 1}};

    std::cout << matrixProcessing(*x, 5, 5) << std::endl;
    return 0;
}