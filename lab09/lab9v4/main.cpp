#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n1, n2;
    cout << "Введите высоту матрицы: ";
    //cin >> n1;
    cout << "Введите ширину матрицы: ";
    //cin >> n2;
    n1=5;n2=5;cout<<endl;
    srand(unsigned(time(nullptr)));
    double k = double(198) / RAND_MAX;
    int a[n1][n2];
    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            a[i][y] = rand() * k - 99;;
        }
    }

    int sum[n2];
    for (int i = 0; i < n2; i++) {
        sum[i] = 0;
        int index = i;
        for (int y = 0; y < n1; y++) {
            sum[i] += abs(a[y][index]);
            index--;
            if (index == -1) {
                index = n2-1;
            }
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            cout << left << setw(4) << a[i][y];
        }
        cout << "|" << sum[i] << endl;
    }
    cout << endl;

    int min = sum[0];
    for (int i = 1; i < n2; i++) {
        if (min > sum[i]) {
            min = sum[i];
        }
    }

    cout << "Min: " << min << endl;

    return 0;
}