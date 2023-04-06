// Created on 4/6/23.

#ifndef BINARYTREE_BST_H
#define BINARYTREE_BST_H

#include <iostream>

namespace BinarySearchTree {
    struct node {
    public:
        int data;
        node* left;
        node* right;
        node* parent;
        node(int d) : data(d), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    class BST {
    public:
        class Position {
        public:
            node* v;
            Position(node*_v = nullptr) : v(_v) {  }
            int& operator*() { return v->data; }
            Position left() { return v->left; }
            Position right() { return v->right; }
            Position parent() { return v->parent; }
//            Position own() {return  ;}
            bool isRoot() const { return v->parent == nullptr; }
            bool isExternal() const {return v->left == nullptr && v->right == nullptr;}
            friend class BinaryTree;
        };
        typedef std::initializer_list<Position>PositionList;
    public:
        BST(int d);
        int size() const;
        bool isEmpty() const;
        Position root() const;
        PositionList positions() const;
        void expandExternal(const Position &p);
        void insert(int d);
        void random(int nodes, int min, int max);
        void printTree() const;
        Position removeAboveExternal(const Position& p);
    protected:
        void preorder(node* v, PositionList& pl);
    private:
        node* _Root;
        int n; // node count
    };



} // BST

#endif //BINARYTREE_BST_H
