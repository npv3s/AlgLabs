#include <cstdio>

#define N 3
#define M 3

int count(int matrix[N][M]) {
    int out = 0;
    for (int i = 0; i < N; i++) {
        for (int y = 0; y < M; y++) {
            if (!(matrix[i][y]&1)) {
                out += 1;
            }
        }
    }
    return out;
}


int main() {
    int m1[N][M], m2[N][M];
    for (int i = 0; i < N; i++) {
        for (int y = 0; y < M; y++) {
            scanf("%d", &m1[i][y]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int y = 0; y < M; y++) {
            scanf("%d", &m2[i][y]);
        }
    }
    int c1 = count(m1), c2 = count(m2);
    if (c1 > c2) {
        printf("Matrix 1 (%d) > Matrix 2 (%d)\n", c1, c2);
    } if (c1 < c2) {
        printf("Matrix 1 (%d) < Matrix 2 (%d)\n", c1, c2);
    } else {
        printf("Matrix 1 (%d) = Matrix 2 (%d)\n", c1, c2);
    }

}