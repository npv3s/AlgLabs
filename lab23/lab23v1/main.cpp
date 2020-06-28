#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool is_int(const string &str) {
    bool is_int = true;
    for (auto letter : str)
        if (isalpha(letter)) is_int = false;
    return is_int;
}

bool is_float(const string &str) {
    bool is_float = false;
    for (auto letter : str)
        if (letter == '.') is_float = true;
    for (auto letter : str)
        if (isalpha(letter)) is_float = false;
    return is_float;
}

int main() {
    ifstream myfile("../example.txt");

    if (!myfile.is_open()) {
        cout << "Нельзя открыть файл!";
        return -1;
    }

    string tmp;
    vector<string> raw;

    while (getline(myfile, tmp))
        raw.push_back(tmp);
    myfile.close();

    for (const string &line : raw) {
        if (is_int(line) and not is_float(line)) {
            int tmp_i = (int) stod(line);
            cout.setf(ios::left);
            cout.fill('#');
            cout.width(7);
            cout << tmp_i << endl;
        } else if (is_float(line)) {
            double tmp_f = stod(line);
            cout.setf(ios::right | ios::scientific);
            cout.fill('_');
            cout.precision(3);
            cout.width(14);
            cout << tmp_f << endl;
        }
    }


    return 0;
}