#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n1, n2;
    cout << "Введите высоту матрицы: ";
    cin >> n1;
    cout << "Введите ширину матрицы: ";
    cin >> n2;
    int a[n1][n2];
    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            a[i][y] = i * n2 + y;
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            cout << left << setw(3) << a[i][y];
        }
        cout << endl;
    }
    cout << endl;

    int val;
    cout << "Введите сдвиг: ";
    cin >> val;

    for (int i = 0; i < val; i++) {
        int tmp = a[0][0];
        for (int y = 0; y < (n1 * n2) - 1; y++) {
            a[y / n2][y % n2] = a[(y + 1) / n2][(y + 1) % n2];
        }
        a[n1 - 1][n2 - 1] = tmp;
    }

    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            cout << left << setw(3) << a[i][y];
        }
        cout << endl;
    }

    return 0;
}