//
// Сортировка пузырьком по убыванию
//

#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    int a_len;
    cout << "Введите к-во элементов: ";
    cin >> a_len;
    srand(unsigned(time(0)));
    double k = double(100)/RAND_MAX;
    int a[a_len];
    for (int i=0; i<a_len; i++){
        a[i] = rand() * k;
    }
	bool is_sorted = false;
	while (!is_sorted) {
	    is_sorted = true;
        for (int i = 0; i < a_len - 1; i++) {
            if (a[i] < a[i + 1]) {
                is_sorted = false;
                int tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
            }
        }
    }
    // Magic array print
    for (const auto& e : a) {
        std::cout << e << std::endl;
    }
}