#ifndef LAB19V3_B_TREE_H
#define LAB19V3_B_TREE_H

struct Node {
    int d;
    Node *left;
    Node *right;
};

Node *first(int d);
Node *search_insert(Node *root, int d);
void print_tree(Node *p, int level);
void print_sorted_tree(Node *p);
void delete_it(Node *root, Node *p);

#endif //LAB19V3_B_TREE_H
