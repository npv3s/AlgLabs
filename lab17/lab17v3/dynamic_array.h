//
// Created by npv3s on 20.04.2020.
//

#ifndef LAB17V3_DYNAMIC_ARRAY_H
#define LAB17V3_DYNAMIC_ARRAY_H

struct Node {
    int d;
    Node *next;
    Node *prev;
};

void print(Node *const array_start);
void add(Node **pend, int d);
Node *find(Node *const pbeg, int key);
bool remove(Node **pbeg, Node **pend, int key);
Node *insert(Node *const pbeg, Node **pend, int key, int d);

#endif //LAB17V3_DYNAMIC_ARRAY_H
