#ifndef LAB18_STACK_H
#define LAB18_STACK_H

struct Location {
    short int x;
    short int y;
};

struct Node {
    Location location;
    Node *p;
};

void push(Node **top, Location location);
Location pop(Node **top);

#endif //LAB18_STACK_H
