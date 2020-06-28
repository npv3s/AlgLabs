#include <iostream>
#include <cstring>
#include "b_tree.h"

using namespace std;

inline void print_word(char *rus, char *eng, int counter) {
    cout << "ru: " << rus << " en: " << eng << " counter: " << counter;
}

char *get_world(Node *root, char *word) {
    Node *tmp = search_insert(root, word);
    tmp->counter++;
    return tmp->rus;
}

Node *first(char *eng, char *rus) {
    Node *pv = new Node;
    pv->eng = new char[strlen(eng) + 1];
    pv->rus = new char[strlen(rus) + 1];
    strcpy(pv->eng, eng);
    strcpy(pv->rus, rus);
    pv->counter = 0;
    pv->left = nullptr;
    pv->right = nullptr;
    return pv;
}

Node *search_insert(Node *root, char *eng, char *rus, int counter, bool sort_by_counter) {
    Node *pv = root;
    Node *prev;
    bool found = false;
    while (pv && !found) {
        prev = pv;
        if (!sort_by_counter) {
            if (strcmp(eng, pv->eng) == 0) found = true;
            else if (strcmp(eng, pv->eng) < 0) pv = pv->left;
            else pv = pv->right;
        } else {
            if (counter == pv->counter) found = true;
            else if (counter < pv->counter) pv = pv->left;
            else pv = pv->right;
        }
    }
    if (found) return pv;
    Node *pnew = new Node;
    pnew->eng = new char[strlen(eng) + 1];
    pnew->rus = new char[strlen(rus) + 1];
    strcpy(pnew->eng, eng);
    strcpy(pnew->rus, rus);
    pnew->counter = counter;
    pnew->left = nullptr;
    pnew->right = nullptr;
    if (!sort_by_counter) {
        if (strcmp(eng, prev->eng) < 0) prev->left = pnew;
        else prev->right = pnew;
    } else {
        if (counter < prev->counter) prev->left = pnew;
        else prev->right = pnew;
    }
    return pnew;
}

void print_tree(Node *p, int level) {
    if (p) {
        print_tree(p->left, level + 1);
        for (int i = 0; i < level; i++) cout << " ";
        print_word(p->rus, p->eng, p->counter);
        cout << endl;
        print_tree(p->right, level + 1);
    }
}

void print_sorted_tree(Node *p) {
    if (p != nullptr) {
        print_sorted_tree(p->left);
        print_word(p->rus, p->eng, p->counter);
        cout << endl;
        print_sorted_tree(p->right);
    }
}

Node *rebuild_tree(Node *p, Node *s) {
    if (p != nullptr) {
        if (s == nullptr)
            s = first(p->eng, p->rus);
        else
            search_insert(s, p->eng, p->rus, p->counter, true);
        if (p->left != nullptr) rebuild_tree(p->left, s);
        if (p->right != nullptr) rebuild_tree(p->right, s);
    }
    return s;
}

void delete_tree(Node *p) {
    if (p == nullptr) return;
    if (p->right != nullptr) delete_tree(p->right);
    if (p->left != nullptr) delete_tree(p->left);
    delete p;
}

Node *find_root(Node *root, Node *p) {
    if (root == p) return p;
    if (root == nullptr) return nullptr;
    if (root->left == p or root->right == p) return root;
    Node *tmp = find_root(root->left, p);
    if (tmp == nullptr) return find_root(root->right, p);
    else return find_root(root->left, p);
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
            delete p_root->left->rus;
            delete p_root->left->eng;
            delete p_root->left;
            p_root->left = nullptr;
        }
        if (p_root->right == p) {
            delete p_root->right->rus;
            delete p_root->right->eng;
            delete p_root->right;
            p_root->right = nullptr;
        }
    } else if (p->left == nullptr or p->right == nullptr) {
        if (p->left == nullptr) {
            if (p_root->left == p) {
                delete p_root->left->rus;
                delete p_root->left->eng;
                delete p_root->left;
                p_root->left = p->right;
            } else {
                delete p_root->right->rus;
                delete p_root->right->eng;
                delete p_root->right;
                p_root->right = p->right;
            }
        } else {
            if (p_root->left == p) {
                delete p_root->left->rus;
                delete p_root->left->eng;
                delete p_root->left;
                p_root->left = p->left;
            } else {
                delete p_root->right->rus;
                delete p_root->right->eng;
                delete p_root->right;
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
        p->eng = tmp_p->eng;
        p->rus = tmp_p->rus;
        p->counter = tmp_p->counter;
        if (next->left == tmp_p) {
            delete p_root->left->rus;
            delete p_root->left->eng;
            delete next->left;
            next->left = nullptr;
        } else {
            delete p_root->right->rus;
            delete p_root->right->eng;
            delete next->right;
            next->right = nullptr;
        }
    }
}