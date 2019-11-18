#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int a_len;
    cout << "Введите к-во элементов: ";
    cin >> a_len;
    srand(unsigned(time(0)));
    double k = double(4)/RAND_MAX;
    double a[a_len];
    double* index = a;
    for (int i=0; i<a_len; i++){
        *(index + i) = rand() * k - 2;
    }

    // Magic array print
    for (const auto& e : a) {
        std::cout << e << std::endl;
    }

    index = a;
    double min=*(index);
    int min_i = -1;
    for (int i=1; i<a_len; i++) {
        double val = *(index + i);
        if ((val < min) and (val <= 1) and (val >= -1)) {
            min = *(index + i);
            min_i = i;
        }
    }
    cout << "Min: " << min << "\nIndex: " << min_i;
}