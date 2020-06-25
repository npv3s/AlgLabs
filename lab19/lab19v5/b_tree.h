//
// Created by npv3s on 18.05.2020.
//

#ifndef LAB19V5_B_TREE_H
#define LAB19V5_B_TREE_H

struct Node {
    char *rus;
    char *eng;
    int counter;
    Node *left;
    Node *right;
};

char *get_world(Node *root, char *word);
Node *first(char *rus, char *eng);
Node *search_insert(Node *root, char *eng, char *rus = nullptr, int counter = 0, bool sort_by_counter = false);
void print_tree(Node *p, int level);
void print_sorted_tree(Node *p);
void delete_it(Node *root, Node *p);
Node *rebuild_tree(Node *p, Node *s);
void delete_tree(Node *p);

#endif //LAB19V5_B_TREE_H
