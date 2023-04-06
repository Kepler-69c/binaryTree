// Created on 4/6/23.

#include <iostream>
#include <random>
#include <functional>
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

void BST::random(int nodes, int min, int max) {
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator
    uniform_int_distribution<int> dis(min, max);

    for (int i = 0; i < nodes; i++)
        this->insert(dis(gen));

}

void BST::printTree() const {
    cout << "In-order traversal: ";
    stack<node*> s;
    node* v = _Root;
    while (!s.empty() || v != nullptr) {
        if (v != nullptr) {
            s.push(v);
            v = v->left;
        }
        else {
            v = s.top();
            s.pop();
            cout << v->data << " ";
            v = v->right;
        }
    }
    cout << endl;
}