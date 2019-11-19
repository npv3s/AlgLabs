#include <iostream>
using namespace std;

int main() {
    int a_len;
    cout << "Введите к-во элементов: ";
    cin >> a_len;
    int a[a_len];
    for (int i=0; i<a_len; i++){
        a[i] = i+1;
    }
    int search;
    cout << "Введите искомое число: ";
    cin >> search;

    int left = 0;
    int right = a_len;
    int mid = 0;
    while (abs(right - left) > 1) {
        mid = (right + left)/2;
        if (a[mid] > search) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << "Index: " << left << endl;
    cout << "Val: " << a[left] << endl;
}