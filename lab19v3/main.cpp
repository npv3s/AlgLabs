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

void print_sorted_tree(Node *p) {
    if (p != nullptr) {
        print_sorted_tree(p->left);
        cout << p->d << endl;
        print_sorted_tree(p->right);
    }
}

Node **minimum(Node **p) {
    if ((*p)->left == nullptr) return p;
    return minimum(&(*p)->left);
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
}

Node *delete_it(Node *root, Node *p) {
    if (p == nullptr) {
        cout << "Нельзя удалить несуществующий элемент!" << endl;
        exit(-1);
    }
    // t — дерево, v  — удаляемый элемент
    //while ((root->right != p) && root->left != p) {
    //    if ((p)->d < root->d) root = root->left;
    //    else root = root->right;
    //}
    Node *p_root = find_root(root, p);
    // p = v.parent                                  // предок удаляемого элемента
    if (p->left == nullptr and p->right == nullptr) {         // первый случай: удаляемый элемент - лист
        if (p_root->left == p) {
            p_root->left = nullptr;
        }
        if (p_root->right == p) {
            p_root->right = nullptr;
        }
    } else if (p->left == nullptr or p->right == nullptr) {     // второй случай: удаляемый элемент имеет одного потомка
        if (p->left == nullptr) {
            if (p_root->left == p) {
                p_root->left = p->right;
            } else {
                p_root->right = p->right;
                //p->right.p_rootarent = p_root;
            }
        } else {
            if (p_root->left == p) {
                p_root->left = p->left;
            } else {
                p_root->right = p->left;
                //p->left.p_rootarent = p_root;
            }
        }
    } else {
        Node *next = p;                // root — корень дерева
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

        /* Node *tmp_root = find_root(root, next);
        if (tmp_root->left == next) {
            tmp_root->left == nullptr;
            //tmp_root->left = next->right;
            if (next->right != nullptr) {
                //next->right.rootarent = tmp_root;
            }
        } else {
            tmp_root->right = nullptr;
            //tmp_root->right = next->left;
            if (next->left != nullptr) {
                //next->right.rootarent = tmp_root;
            }
        } */
    }
}
/*
Node *search_delete(Node *root, int d) {
    Node *pv = root;
    Node *prev;
    if ((pv->left == nullptr) && (pv->right == nullptr)) {
        if (!side) { prev->left = nullptr; }
        else { prev->right = nullptr; }
    } else if ((pv->left == nullptr) && (pv->right != nullptr)) {
        if (!side) { prev->left = pv->right; }
        else { prev->right = pv->right; }
    } else if ((pv->left != nullptr) && (pv->right == nullptr)) {
        if (!side) { prev->left = pv->left; }
        else { prev->right = pv->left; }
    } else {
        Node *prev = pv;
        pv = pv->left;
        while ((pv->left != nullptr) && (pv->right != nullptr)) { pv = pv->right; }
        int temp = (pv->d);
        search_delete(root, temp);
        prev->d = temp;
    }
    return pv;
}
*/

/* Node** delete_item(Node **root, int val) {
    if (root == nullptr)
        return root;
    if (val < (*root)->d) {
        (*root)->left = *delete_item(&(*root)->left, val);
    } else if (val > (*root)->d) {
        *(*root)->right = *delete_item(&(*root)->right, val);
    } else if ((*root)->left != nullptr and (*root)->right != nullptr) {
        (*root)->d = (*minimum(&(*root)->right))->d;
        (*root)->right = *delete_item(&(*root), (*root)->d);
    } else {
        if ((*root)->left != nullptr) {
            *root = (*root)->left;
        } else if ((*root)->right != nullptr) {
            *root = (*root)->right;
        } else {
            *root = nullptr;
            return root;
        }
    }
} */

/*
void delete_item(Node **root, Node **p) {
    if (((*p)->left == nullptr) && ((*p)->right == nullptr)) {
        if (root == p) {
            cout << "Нельзя удалить последний элемент!" << endl;
            exit(-1);
        }
        //Node *root = root;
        while (((*root)->right != *p) && (*root)->left != *p) {
            if ((*p)->d < (*root)->d) *root = (*root)->left;
            else *root = (*root)->right;
        }
        if ((*root)->right == *p) {
            //delete p;
            (*root)->right = nullptr;
        } else {
            (*root)->left = nullptr;
            //delete p;
        }
    } else {
        Node *tmp_p = (*p)->right;
        Node *tmp_previous = *p;
        if (tmp_p != nullptr) {
            while (tmp_p->left) {
                tmp_previous = tmp_p;
                tmp_p = tmp_p->left;
            }
        }
        Node *right = tmp_p;
        Node *right_before = tmp_previous;
        tmp_p = (*p)->left;
        if (tmp_p != nullptr) {
            while (tmp_p->right) {
                tmp_previous = tmp_p;
                tmp_p = tmp_p->right;
            }
        }
        Node *left = tmp_p;
        Node *left_before = tmp_previous;
        if ((left == nullptr) && (right != nullptr)) {
            (*p)->d = right->d;
            delete right;
        } else if ((left != nullptr) && (right == nullptr)) {
            (*p)->d = left->d;
            delete left;
        } else {
            cout << right->d << endl;
            (*p)->d = right->d;
            delete right;
        }
    }
}

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

