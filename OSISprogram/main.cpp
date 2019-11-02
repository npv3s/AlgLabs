#include <iostream>
#include <string>
using namespace std;

int main() {
    string arg;
    cout << "1. ping <arg>\n2. ls <arg>\n3. echo <arg>\n4. mkdir <arg>\n5. tree <arg>\nВыбирите режим работы: ";
    int mode;
    cin >> mode;
    switch (mode) {
        case 1:
            cout << "Введите адрес: ";
            cin >> arg;
            system(string(string("ping -c 5 ") + arg).c_str());
            break;
        case 2:
            cout << "Введите путь: ";
            cin >> arg;
            system(string(string("ls ") + arg).c_str());
            break;
        case 3:
            cout << "Введите текст: ";
            cin >> arg;
            system(string(string("echo ") + arg).c_str());
            break;
        case 4:
            cout << "Введите название папки: ";
            cin >> arg;
            system(string(string("mkdir /home/npv3s/") + arg).c_str());
            break;
        case 5:
            cout << "Введите путь: ";
            cin >> arg;
            system(string(string("tree ") + arg).c_str());
            break;
        default:
            cout << "Команда не опознана!" << endl;
    }
    return 0;
}