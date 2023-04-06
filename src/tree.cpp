// Created: 3/30/23.

#include <iostream>
#include "tree.h"

using namespace tree;


BinaryTree::BinaryTree() : _Root(nullptr), n(0) {} //constructor

int BinaryTree::size() const { return n; }

bool BinaryTree::isEmpty() const { return size() == 0; }

BinaryTree::Position BinaryTree::root() const { return Position(_Root); }

void BinaryTree::addRoot() { _Root = new node; n = 1;}

void BinaryTree::expandExternal( const Position &p) {
    node* v = p.v;
    v->left = new node;
    v->left->parent = v;
    v->right = new node;
    v->right->parent = v;
    n += 2;
}

BinaryTree::Position BinaryTree::removeAboveExternal(const Position& p) {
    node* w = p.v; node* v = w->parent;
    node* sib = (w == v->left ? v->right : v->left);
    if (w->left == nullptr && w->right == nullptr) {
        if (v == _Root) {
            _Root = sib;
            sib->parent = nullptr;
        }
        else {
            node* grandparent = v->parent;
            if (grandparent->left == v) grandparent->left = sib;
            else grandparent->right = sib;
        }
        delete w; delete v;
        n -= 2;
        return Position(sib);
    }
}