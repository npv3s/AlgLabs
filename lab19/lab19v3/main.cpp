#include <iostream>
#include "b_tree.h"

using namespace std;

int main() {
    int b[] = {1, 2, 3, 4, 5};
    Node *root = first(b[1]);
    for (int i : b)
        search_insert(root, i);
    print_tree(root, 0);
    delete_it(root, root);
    delete_it(root, root->right);
    cout << endl;
    print_tree(root, 0);
    cout << endl;
    return 0;
}

