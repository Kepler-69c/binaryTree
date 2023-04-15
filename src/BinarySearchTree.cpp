// Created on 4/6/23.

#include <iostream>
#include <random>
#include <functional>
#include <stack>
#include "BinarySearchTree.h"

using namespace BinarySearchTree;
using namespace std;

int randomNum(int min, int max) {
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

BST::BST(int d) {
    _Root = nullptr;
    n=0;
    addRoot(d);
}

void BST::addRoot(int d) { _Root = new node(d); n = 1;}

int BST::size() const {return n;}
bool BST::isEmpty() const {return size() == 0;}

BST::Position BST::root() const { return Position(_Root);}

void BST::expandExternal(const Position &p, int left, int right) {
    node* v = p.v;
    v->left = new node(left);
    v->left->parent = v;
    v->right = new node(right);
    v->right->parent = v;
    n += 2;
}

void BST::insertByValue(int d) {
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

void BST::insertRandom(int d) {
    node* v = _Root;
    node* p = nullptr;

    while (v != nullptr) {
        p = v;
        // Randomly decide whether to go left or right
        if (randomNum(0, 1) == 0) {
            v = v->left;
        } else {
            v = v->right;
        }
    }

    // Insert the new node in the missing place
    if (randomNum(0, 1) == 0) {
        p->left = new node(d);
        p->left->parent = p;
    } else {
        p->right = new node(d);
        p->right->parent = p;
    }

    n++;
}

int BST::getFromDepth(int depth) {
    node* v = _Root;
    int current_depth = 0;
    while (v != nullptr) {
        if (current_depth == depth) {
            // Randomly select whether to return left or right node
            if (randomNum(0, 1) == 0 && v->left != nullptr) {
                return v->left->data;
            } else if (v->right != nullptr) {
                return v->right->data;
            }
        }
        // Traverse to the next level of the tree
        if (randomNum(0, 1) == 0 && v->left != nullptr) {
            v = v->left;
        } else if (v->right != nullptr) {
            v = v->right;
        } else {
            // If neither left nor right child exists, backtrack to parent
            v = v->parent;
        }
        current_depth++;
    }
    return -1; // no node at depth 'depth'
}


void BST::random(int nodes, int min, int max) {
    random(nodes, min, max, false);
}

void BST::random(int nodes, int min, int max, bool insertByValue) {
    for (int i = 0; i < nodes; i++)
        if (insertByValue)
            this->insertByValue(randomNum(min, max));
        else
            this->insertRandom(randomNum(min, max));
}