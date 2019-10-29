#include <iostream>

using namespace std;

int main() {
    enum Week {
        MON = 1,
        TUES,
        WED,
        THURS,
        FRI,
        SAT,
        SUN
    };
    cout << "Введите номер дня недели: ";
    int c;
    cin >> c;
    switch (c) {
        case (MON):
            cout << "«Понедельник», в буквальном переводе с японского, — «день луны»" << endl;
            break;
        case (TUES):
            cout << "«Вторник», в буквальном переводе с японского, — «день огня»" << endl;
            break;
        case (WED):
            cout << "«Среда», в буквальном переводе с японского, — «день воды»" << endl;
            break;
        case (THURS):
            cout << "«Четверг», в буквальном переводе с японского, — «день дерева»" << endl;
            break;
        case (FRI):
            cout << "«Пятница», в буквальном переводе с японского, — «день золота, метала»" << endl;
            break;
        case (SAT):
            cout << "«Суббота», в буквальном переводе с японского, — «день земли»" << endl;
            break;
        case (SUN):
            cout << "«Воскресенье», в буквальном переводе с японского, — «день солнца»" << endl;
            break;

    }
    return 0;
}