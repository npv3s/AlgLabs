#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n1 = 5, n2 = 5;
    srand(unsigned(time(nullptr)));
    double k = double(198) / RAND_MAX;
    int a[n1][n2];
    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            a[i][y] = rand() * k - 99;
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            cout << left << setw(4) << a[i][y];
        }
        cout << endl;
    }
    cout << endl;

    int sum[n1];
    for (int i = 0; i < n1; i++) {
        sum[i] = 0;
        for (int y = 0; y < n2; y++) {
            if ((a[i][y] % 2 == 0) and (a[i][y] > 0)) {
                sum[i] += a[i][y];
            }
        }
    }

    for (int i = 0; i < n1; i++) {
        int max = 0;
        for (int y = 1; y < n1; y++) {
            if (sum[max] < sum[y]) {
                max = y;
            }
        }
        for (int z = 0; z < n2; z++) {
            cout << left << setw(4) << a[max][z];
        }
        cout << "|" << sum[max] << endl;
        sum[max] = -1;
    }

    return 0;
}