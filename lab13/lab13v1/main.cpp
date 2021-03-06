#include <iostream>
#include <cmath>
using namespace std;

// Функция для подсчёта дистанции от начала координат до точки
int distanceFromCenter(int x, int y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main() {
    int radius;
    // Ввод радиуса, в пределах которого происходит подсчёт точек
    cout << "Введите радиус: ";
    cin >> radius;
    //radius = 3;
    // Введение исходных списков точек
    int x[] = {0, -3, 5, 3, -4, 5, 0, 4, 2, 4};
    int y[] = {3, -3, -5, 5, 0, -2, 4, -5, 1, 1};
    // Введение переменной для подсчёта точек, удовлетворяющих условию
    unsigned int sum = 0;
    // Цикл, с помощью которого происходит перебор всех точек
    for(int i = 0; i < 10; i++) {
        // Проверка числа с помощью фунции
        if (distanceFromCenter(x[i], y[i]) <= radius) {
            // Подсчёт подходящих элементов
            sum++;
        }
    }
    // Вывод к-ва точек удовлетворяющих условию
    cout << "К-во точек в радиусе: " << sum << endl;
    return 0;
}
