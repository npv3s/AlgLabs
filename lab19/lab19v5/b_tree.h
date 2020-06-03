//
// Created by npv3s on 18.05.2020.
//

#ifndef LAB19V5_B_TREE_H
#define LAB19V5_B_TREE_H

#define WORD_SIZE 256

struct Word {
    char rus[WORD_SIZE];
    char eng[WORD_SIZE];
    int counter;
};

struct Node {
    Word d;
    Node *left;
    Node *right;
};

Node *first(Word d);
Node *search_insert(Node *root, Word d, bool sort_by_counter);
void print_tree(Node *p, int level);
void print_sorted_tree(Node *p);
void delete_it(Node *root, Node *p);

#endif //LAB19V5_B_TREE_H
