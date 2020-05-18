//
// Created by npv3s on 18.05.2020.
//

#include <iostream>
#include "b_tree.h"

using namespace std;

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

void print_sorted_tree(Node *p) {
    if (p != nullptr) {
        print_sorted_tree(p->left);
        cout << p->d << endl;
        print_sorted_tree(p->right);
    }
}

Node *find_root(Node *root, Node *p) {
    if (root == p) return p;
    while ((root->right != p) && root->left != p) {
        if ((p)->d < root->d) root = root->left;
        else root = root->right;
    }
    return root;
}

Node *is_list(Node *p) {
    if (p->left != nullptr) {
        if ((p->left->left == nullptr) and (p->left->right == nullptr)) {
            return p->left;
        } else {
            return nullptr;
        }
    } else if (p->right != nullptr) {
        if ((p->right->left == nullptr) and (p->right->right == nullptr)) {
            return p->right;
        } else {
            return nullptr;
        }
    }
    return nullptr;
}

void delete_it(Node *root, Node *p) {
    if (p == nullptr) {
        cout << "Нельзя удалить несуществующий элемент!" << endl;
        exit(-1);
    }
    Node *p_root = find_root(root, p);
    if (p->left == nullptr and p->right == nullptr) {
        if (p_root->left == p) {
            p_root->left = nullptr;
        }
        if (p_root->right == p) {
            p_root->right = nullptr;
        }
    } else if (p->left == nullptr or p->right == nullptr) {
        if (p->left == nullptr) {
            if (p_root->left == p) {
                p_root->left = p->right;
            } else {
                p_root->right = p->right;
            }
        } else {
            if (p_root->left == p) {
                p_root->left = p->left;
            } else {
                p_root->right = p->left;
            }
        }
    } else {
        Node *next = p;
        while (is_list(next) == nullptr) {
            if (next->left != nullptr) {
                next = next->left;
            } else {
                next = next->right;
            }
        }
        Node *tmp_p = is_list(next);
        p->d = tmp_p->d;
        if (next->left == tmp_p) {
            next->left = nullptr;
        } else {
            next->right = nullptr;
        }
    }
}