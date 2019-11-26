#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n1 = 5, n2 = 5;
    srand(unsigned(time(nullptr)));
    double k = double(99) / RAND_MAX;
    int a[n1][n2];
    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            a[i][y] = rand() * k;
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            cout << left << setw(4) << a[i][y];
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n1; i++) {
        int max = 0, y;
        for (y = 1; y < n2; y++) {
            if (a[i][max] < a[i][y]) {
                max = y;
            }
        }
        int tmp = a[i][max];
        a[i][max] = a[i][i];
        a[i][i] = tmp;
    }

    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            cout << left << setw(4) << a[i][y];
        }
        cout << endl;
    }


    return 0;
}