#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n1, n2;
    cout << "Введите высоту матрицы: ";
    //cin >> n1;
    cout << "Введите ширину матрицы: ";
    //cin >> n2;
    n1 = 10;
    n2 = 10;
    cout << endl;
    srand(unsigned(time(nullptr)));
    double k = double(4) / RAND_MAX;
    int a[n1][n2];
    for (int i = 0; i < n1; i++) {
        for (int y = 0; y < n2; y++) {
            a[i][y] = rand() * k;
        }
    }

    int max[n1];
    for (int i = 0; i < n1; i++) {
        int local_max[n2][2];

        for (int y = 0; y < n2; y++) {
            local_max[y][0] = 0;
            local_max[y][1] = 0;

            int z;
            for (z = y; z < n2; z++) {
                local_max[y][1]++;
                z++;
                while (a[i][z] == a[i][z - 1] and z < n2) {
                    if (a[i][y] == a[i][z]) {
                        local_max[y][1]++;
                    }
                    z++;
                }
                if (local_max[y][0] < local_max[y][1]) {
                    local_max[y][0] = local_max[y][1];
                }
                local_max[y][1] = 0;
            }
        }
        max[i] = 0;
        for (int y = 0; y < n2; y++) {
            if (local_max[y][0] > max[i]) {
                max[i] = local_max[y][0];
            }
        }
    }

    int max_raw = max[0];
    for (int i = 0; i < n1; i++) {
        if (max[max_raw] < max[i]) {
            max_raw = i;
        }

        for (int y = 0; y < n2; y++) {
            cout << left << setw(3) << a[i][y];
        }
        cout << "|" << max[i] << endl;
    }
    cout << endl;
    cout << "Max raw: " << max_raw+1 << endl;

    return 0;
}