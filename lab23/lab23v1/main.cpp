#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool is_int(const string &str) {
    bool is_digit = true;
    for (char d : str)
        if (not isdigit(d) or isspace(d)) {
            is_digit = false;
            break;
        }
    return is_digit;
}

bool is_float(const string &str) {
    for (char d : str) cout << "|" << d << "|";
    cout << endl;
    int tmp = -1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.')
            tmp = i;
    }
    if (tmp == -1) return false;
    bool is_float = false;
    for (int i = 0; i < str.size(); i++) {
        if (not(isdigit(str[i]) or i == tmp or isspace(str[i])))
            is_float = false;
    }
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
        cout << line << endl;
        cout << is_int(line) << " " << is_float(line) << endl;
        if (is_int(line)) {
            int tmp_i = (int) stod(line);
            cout.setf(ios::left);
            cout.fill('#');
            //cout.precision(4);
            cout.width(7);
            cout << tmp_i << endl;
        } else if (is_float(line)) {
            double tmp_f = stod(line);
            cout.setf(ios::scientific);
            cout.fill('_');
            cout.precision(3);
            cout.width(14);
            cout << tmp_f << endl;
        }
    }


    return 0;
}