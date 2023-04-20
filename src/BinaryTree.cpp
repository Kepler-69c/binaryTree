// Created on 4/6/23.

#include <stack>
#include <queue>
#include "BinaryTree.h"
#include "xorshift.h"

using namespace BinaryTree;
using namespace std;

BT::BT(int d) {
    _Root = nullptr;
    n=0;
    addRoot(d);
}

void BT::addRoot(int d) { _Root = new node(d); n = 1;}

int BT::size() const {return n;}
bool BT::isEmpty() const {return size() == 0;}

BT::Position BT::root() const { return Position(_Root);}

void BT::expandExternal(const Position &p, int left, int right) {
    node* v = p.v;
    v->left = new node(left);
    v->left->parent = v;
    v->right = new node(right);
    v->right->parent = v;
    n += 2;
}

int BT::depth() const {
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

void BT::insertByValue(int d) {
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
void BT::insertRandom(int d) {
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

int BT::getFromDepth(int depth) {
    Xorshift128Plus rng;
    std::vector<Position> positions;
    positions.push_back(root());
    while (!positions.empty()) {
        Position p = positions.back();
        positions.pop_back();
        if (p.v != nullptr && depth > 0) {
            positions.push_back(p.left());
            positions.push_back(p.right());
            depth--;
        } else if (p.v != nullptr && depth == 0) {
            positions.push_back(p.left());
            positions.push_back(p.right());
            if (p.isExternal()) {
                std::vector<int> values;
                while (!p.isRoot()) {
                    values.push_back(*p);
                    p = p.parent();
                }
                values.push_back(*p);
                return values[rng.random_integer(0, values.size() - 1)];
            }
        }
    }
    throw std::out_of_range("Depth too large for tree");
}

// TODO: there must be a nicer solution for optional parameters than overloading
void BT::random(int nodes, int min, int max) {
    random(nodes, min, max, false);
}

void BT::random(int nodes, int min, int max, bool insertByValue) {
    Xorshift128Plus rng;
    for (int i = 0; i < nodes; i++)
        // Should the new node be inserted according yo the value / randomly?
        if (insertByValue)
            this->insertByValue(rng.random_integer(min, max));
        else
            this->insertRandom(rng.random_integer(min, max));
}