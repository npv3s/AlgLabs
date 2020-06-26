#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template<class Type>
vector<Type> sort(vector<Type> array) {
    int j = 0;
    Type tmp;
    for (int i = 0; i < array.size(); i++) {
        j = i;
        for (int k = i; k < array.size(); k++) {
            if (array[j] > array[k]) {
                j = k;
            }
        }
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    return array;
}

template<class Type>
void print(vector<Type> array) {
    cout << array[0];
    for (int i = 1; i < array.size(); i++)
        cout << " " << array[i];
    cout << endl;
}

int main() {
    ifstream myfile("../digits.txt");

    if (!myfile.is_open()) {
        cout << "Нельзя открыть файл!";
        return -1;
    }

    string tmp;
    vector<string> raw;
    while (getline(myfile, tmp))
        raw.push_back(tmp);
    myfile.close();

    vector<double> vec;
    vec.reserve(raw.size());
    for (const string &line : raw)
        vec.push_back(stod(line));

    print(vec);
    vec = sort(vec);
    print(vec);

    return 0;
}
