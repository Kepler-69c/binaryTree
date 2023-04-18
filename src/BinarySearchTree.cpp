// Created on 4/6/23.

#include <stack>
#include <queue>
#include "BinarySearchTree.h"
#include "xorshift.h"

using namespace BinarySearchTree;
using namespace std;

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

int BST::depth() const {
    if (isEmpty()) {
        return 0;
    }
    int max_depth = 0;
    std::stack<std::pair<node*, int>> s;
    s.push(std::make_pair(_Root, 1));
    while (!s.empty()) {
        auto curr = s.top();
        s.pop();
        max_depth = std::max(max_depth, curr.second);
        if (curr.first->left) {
            s.push(std::make_pair(curr.first->left, curr.second + 1));
        }
        if (curr.first->right) {
            s.push(std::make_pair(curr.first->right, curr.second + 1));
        }
    }
    return max_depth;
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

// TODO: values can be inserted randomly multiple times -> fix
void BST::insertRandom(int d) {
    Xorshift128Plus rng;
    node* v = _Root;
    node* p = nullptr;

    while (v != nullptr) {
        p = v;
        // Randomly decide whether to go left or right
        if (rng.random_integer(0, 1) == 0)
            v = v->left;
        else
            v = v->right;
    }

    // Insert the new node in the missing place
    if (rng.random_integer(0, 1) == 0) {
        p->left = new node(d);
        p->left->parent = p;
    } else {
        p->right = new node(d);
        p->right->parent = p;
    }
    n++;
}

int BST::getFromDepth(int depth) {
    Xorshift128Plus rng;
    node* v = _Root;
    int current_depth = 0;
    while (v != nullptr) {
        if (current_depth == depth) {
            // Randomly select whether to return left or right node
            if (rng.random_integer(0, 1) == 0 && v->left != nullptr) {
                return v->left->data;
            } else if (v->right != nullptr) {
                return v->right->data;
            }
        }
        // Traverse to the next level of the tree
        if (rng.random_integer(0, 1) == 0 && v->left != nullptr)
            v = v->left;
        else if (v->right != nullptr)
            v = v->right;
        else
            v = v->parent; // backtrack to parent if no child exists
        current_depth++;
    }
    return -1; // No node at depth 'depth'
}

// TODO: there must be a nicer solution for optional parameters than overloading
void BST::random(int nodes, int min, int max) {
    random(nodes, min, max, false);
}

void BST::random(int nodes, int min, int max, bool insertByValue) {
    Xorshift128Plus rng;
    for (int i = 0; i < nodes; i++)
        // Should the new node be inserted according yo the value / randomly?
        if (insertByValue)
            this->insertByValue(rng.random_integer(min, max));
        else
            this->insertRandom(rng.random_integer(min, max));
}