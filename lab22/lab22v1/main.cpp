#include <iostream>
using namespace std;

template<class Type>
void sort(Type *data, int size) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < (size - 1); i++) {
            if (data[i] > data[i+1]) {
                sorted = false;
                Type tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}

template<class Type>
void print(Type *data, int size) {
    cout << data[0];
    for (int i = 1; i < size; i++)
        cout << " " << data[i];
    cout << endl;
}

int main() {
    int array[] = {46, 34, 81, 61, 31, 42, 16, 32, 91, 87};
    float array2[] = {6.5, 9.6, 9.1, 8.2, 5.0, 3.7, 9.4, 4.2, 1.0, 1.5};

    print(array, 10);
    sort(array, 10);
    print(array, 10);

    print(array2, 10);
    sort(array2, 10);
    print(array2, 10);

    return 0;
}
