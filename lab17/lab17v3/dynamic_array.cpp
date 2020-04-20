//
// Created by npv3s on 20.04.2020.
//

#include <iostream>
#include "dynamic_array.h"

using namespace std;

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
    bool is_sorted = false;
    while (!is_sorted) {
        is_sorted = true;
        for (int i = 0; i < len - 1; i++) {
            if (vals[i] > vals[i + 1]) {
                is_sorted = false;
                int tmp = vals[i];
                vals[i] = vals[i + 1];
                vals[i + 1] = tmp;
            }
        }
    }
    for (const auto &e : vals) {
        cout << e << " ";
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