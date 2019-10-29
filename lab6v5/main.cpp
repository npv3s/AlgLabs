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
        wcout << L"Введите количество блюда \"" << menu[i] << L"\": ";
        cin >> amount[i];
        sum[i] = amount[i]*price[i];
    }
    wcout << L"┌───────────────┬──────────┬──────────┬──────────┐" << endl;
    wcout << L"|Наименование   |Цена за шт|Кол-во    |Сумма     |" << endl;
    wcout << L"├───────────────┼──────────┼──────────┼──────────┤" << endl;
    for (i=0; i<5; i++) {
        if (amount[i] != 0) {
            wcout << L"|" << setw(15) << left << menu[i] << L"|" << setw(10) << right << price[i] << L"|" << setw(10) <<  amount[i] << L"|" << setw(10) << sum[i] << L"|" << endl;
        }

    }



    return 0;
}