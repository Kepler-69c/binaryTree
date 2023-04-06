// Created on 4/6/23.

#include <iostream>
#include <stack>
#include "BinarySearchTree.h"

using namespace BinarySearchTree;
using namespace std;

BST::BST(int d) {
    _Root = new node(d);//nullptr;
    n = 0;
}
int BST::size() const {return n;}
bool BST::isEmpty() const {return size() == 0;}

BST::Position BST::root() const { return Position(_Root);}

void BST::expandExternal(const Position &p) {
    node* v = p.v;
    v->left = new node(NULL);
    v->left->parent = v;
    v->right = new node(NULL);
    v->right->parent = v;
    n += 2;
}

void BST::insert(int d) {
    node* v = _Root;
    node* p = nullptr;
    while (v != nullptr) {
        p = v;
        if (d < v->data)
            v = v->left;
        else if (d > v->data)
            v = v->right;
        else
            return; // d already exists in tree
    }
    node* new_node = new node(d);
    new_node->parent = p;
    if (p == nullptr) {
        _Root = new_node; // tree was empty
    } else if (d < p->data) {
        p->left = new_node;
    } else {
        p->right = new_node;
    }
    this->n++;
}


}
