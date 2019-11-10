#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main() {
    setlocale(LC_ALL, "");
    wstring menu[5] = { L"Оливье", L"Цезарь", L"Блинчики", L"Компот", L"Булочка"};
    int price[5] = {100, 200, 80, 20, 10};
    int amount[5];
    int sum[5];

    int i;
    for (i=0; i<5; i++) {
        wcout << L"Введите количество блюд \"" << menu[i] << L"\": ";
        cin >> amount[i];
        sum[i] = amount[i]*price[i];
    }
    wcout << L"┌───────────────┬──────────┬──────────┬──────────┐" << endl;
    wcout << L"|Наименование   |Цена за шт|Кол-во    |Сумма     |" << endl;
    wcout << L"├───────────────┼──────────┼──────────┼──────────┤" << endl;
    for (i=0; i<5; i++) {
        if (amount[i] != 0) {
            wcout << L"| " << setw(14) << left << menu[i] << L"|" << setw(10) << right << price[i] << L"|" << setw(10)
                  << amount[i] << L"|" << setw(10) << sum[i] << L"|" << endl;
        }
    }
    wcout << L"└───────────────┴──────────┴──────────┴──────────┘" << endl;
    int total_sum = 0;
    for (i = 0; i < 5; i++) { total_sum += sum[i]; }
    int sum_end = total_sum;
    sum_end = sum_end % 100;
    wstring total;
    if (sum_end >= 11 && sum_end <= 19) {
        total = L"рублей";
    } else {
        i = sum_end % 10;
        switch (i) {
            case (1):
                total = L"рубль";
                break;
            case (2):
            case (3):
            case (4):
                total = L"рубля";
                break;
            default:
                total = L"рублей";
        }
    }
    total = L"Итог: " + to_wstring(total_sum) + L" " + total;
    wcout << setw(50) << total << endl;
    return 0;
}