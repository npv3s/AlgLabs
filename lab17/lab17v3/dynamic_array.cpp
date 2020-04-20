//
// Created by npv3s on 20.04.2020.
//

#include <iostream>
#include "dynamic_array.h"
using namespace std;

int min(int *const val, int start, int end) {
    int tmp = val[start];
    for (int i = start+1; i < end; i++) {
        if (tmp > val[i]) tmp = val[i];
    }
    return tmp;
}

void print(Node *const array_start) {
    Node *tmp_pointer = array_start;
    int len = 1;
    while (tmp_pointer) {
        tmp_pointer = tmp_pointer->next;
        len++;
    }
    int vals[--len];
    tmp_pointer = array_start;
    for (int i = 0; i < len; i++) {
        vals[i] = tmp_pointer->d;
        tmp_pointer = tmp_pointer->next;
    }
    for (int i = 0; i < len; i++) {
        cout << min(vals, i, len) << " ";
    }
    cout << endl;
}

void add(Node **pend, int d) {
    Node *pv = new Node;
    pv->d = d;
    pv->next = nullptr;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}

Node *find(Node *const pbeg, int key) {
    Node *pv = pbeg;
    while (pv) {
        if (pv->d == key) break;
        pv = pv->next;
    }
    return pv;
}

bool remove(Node **pbeg, Node **pend, int key) {
    if (Node *pkey = find(*pbeg, key)) {
        if (pkey == *pbeg) {
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = nullptr;
        } else if (pkey == *pend) {
            *pend = (*pend)->prev;
            (*pend)->next = nullptr;
        } else {
            (pkey->prev)->next = pkey->next;
            (pkey->next)->prev = pkey->prev;
        }
        delete pkey;
        return true;
    }
    return false;
}

Node *insert(Node *const pbeg, Node **pend, int key, int d) {
    if (Node *pkey = find(pbeg, key)) {
        Node *pv = new Node;
        pv->d = d;
        pv->next = pkey->next;
        pv->prev = pkey;
        pkey->next = pv;
        if (pkey != *pend)
            (pv->next)->prev = pv;
        else
            *pend = pv;
        return pv;
    }
    return nullptr;
}