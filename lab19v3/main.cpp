#include <iostream>

using namespace std;

struct Node {
    int d;
    Node *left;
    Node *right;
};

Node *first(int d) {
    Node *pv = new Node;
    pv->d = d;
    pv->left = nullptr;
    pv->right = nullptr;
    return pv;
}

Node *search_insert(Node *root, int d) {
    Node *pv = root;
    Node *prev;
    bool found = false;
    while (pv && !found) {
        prev = pv;
        if (d == pv->d) found = true;
        else if (d < pv->d) pv = pv->left;
        else pv = pv->right;
    }
    if (found) return pv;
    Node *pnew = new Node;
    pnew->d = d;
    pnew->left = nullptr;
    pnew->right = nullptr;
    if (d < prev->d)
        prev->left = pnew;
    else
        prev->right = pnew;
    return pnew;
}

void print_tree(Node *p, int level) {
    if (p) {
        print_tree(p->left, level + 1);
        for (int i = 0; i < level; i++) cout << " ";
        cout << p->d << endl;
        print_tree(p->right, level + 1);
    }
}

void delete_item(Node **root, Node **p) {
    if ((*p->left == nullptr) && (p->right == nullptr)) {
        if (root == p) {
            cout << "Нельзя удалить последний элемент!" << endl;
            exit(-1);
        }
        //Node *root = root;
        while ((root->right == p) || (root->left == p)) {
            if (p->d < root->d) root = root->left;
            else root = root->right;
        }
        if (root->right == p) {
            root->right = nullptr;
            delete p;
        } else {
            root->left = nullptr;
            delete p;
        }

    }
}

/*
void delete_item(Node* p) {
    cout << p->d << endl;
    Node *tmp_p = p->right;
    Node *tmp_previous = p;
    if (tmp_p != nullptr) {
        while (tmp_p->left) {
            tmp_previous = tmp_p;
            tmp_p = tmp_p->left;
        }
    }
    Node *right = tmp_p;
    Node *right_before = tmp_previous;
    tmp_p = p->left;
    if (tmp_p != nullptr) {
        while (tmp_p->right) {
            tmp_previous = tmp_p;
            tmp_p = tmp_p->right;
        }
    }
    Node *left = tmp_p;
    Node *left_before = tmp_previous;
    if ((left == nullptr) && (right != nullptr)) {
        left_before->left = nullptr;
        delete left;
    } else if ((left != nullptr) && (right == nullptr)) {
        right_before->right = nullptr;
        delete right;
    } else if ((left == nullptr) && (right == nullptr)) {
        delete p;
    }
}*/

int main() {
    int b[] = {10, 25, 20};
    Node *root = first(b[2]);
    for (int i : b)
        search_insert(root, i);
    print_tree(root, 0);
    //for (int i = 0; i < 3; i++) delete_item(root, root);
    delete_item(root, root->left);
    delete_item(root, root->right);
    cout << endl;
    return 0;
}

