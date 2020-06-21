#include <iostream>

using namespace std;

template<class Type, class Size>
class Stack {
    Size size = 0;
    struct Node {
        Type data;
        Node *p;
    };
    Node *top = nullptr;
public:
    void push(const Type data) {
        Node *tmp_p = new Node;
        (*tmp_p).data = data;
        (*tmp_p).p = (*this).top;
        (*this).top = tmp_p;
        size++;
    }

    Type pop() {
        Type tmp = (*(*this).top).data;
        Node *tmp_p = (*this).top;
        (*this).top = (*this).top->p;
        delete tmp_p;
        size--;
        return tmp;
    }

    inline Size get_size() {
        return size;
    }
};

int main() {
    Stack<float, unsigned int> stack;
    float array[] = {76, 59, 28, 52, 91};

    for (auto i : array)
        stack.push(i);
    cout << "size: " << stack.get_size() << endl;
    for (auto _ : array)
        cout << stack.pop() << endl;
    cout << "size: " << stack.get_size() << endl;

    return 0;
}
