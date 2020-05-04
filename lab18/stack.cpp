#include "stack.h"

void push(Node **top, const Location location)
{
    Node *pv = new Node;
    pv->location = location;
    pv->p = *top;
    *top = pv;
}

Location pop(Node **top)
{
    Location temp = (*top)->location;
    Node *pv = *top;
    *top = (*top)->p;
    delete pv;
    return temp;
}
