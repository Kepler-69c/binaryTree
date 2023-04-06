// Created: 3/30/23.

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include <iostream>

namespace tree {

    struct node {
    public:
        int data{};
        node* left;
        node* right;
        node* parent;
        node() : left(NULL), right(NULL), parent(NULL) {} // default constructor needed for "addRoot" function
    };

    class BinaryTree {
    public:
        class Position {
        private:
            node* v;
        public:
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
        BinaryTree();
        int size() const;
        bool isEmpty() const;
        Position root() const;
        PositionList positions() const;
        void addRoot();
        void expandExternal(const Position &p);
        Position removeAboveExternal(const Position& p);
    protected:
        void preorder(node* v, PositionList& pl);
    private:
        node* _Root;
        int n; // node count
    };

}



#endif //BINARYTREE_TREE_H
