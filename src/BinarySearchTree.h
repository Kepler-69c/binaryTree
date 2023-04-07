// Created on 4/6/23.

#ifndef BINARYTREE_BST_H
#define BINARYTREE_BST_H

#include <iostream>

//En dehors des fonctions "insert()" et "random()", l'arbre de recherche binaire
// peut également être utilisé comme un arbre binaire normal. Exemple:
//
//BST binaryTree(1);
//binaryTree.expandExternal(binaryTree.root().left(), 2, NULL);
//binaryTree.printTree();

namespace BinarySearchTree {
    struct node {
    public:
        int data;
        node* left;
        node* right;
        node* parent;
        node(int d) : data(d), left(NULL), right(NULL), parent(NULL) {}
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
    private:
        node* _Root{};
        int n; // node count
    public:
        BST(int d);
        int size() const;
        bool isEmpty() const;
        Position root() const;
        PositionList positions() const;
        void addRoot(int d);
        void printTree() const;
        //BST functions:
        void insert(int d);
        void random(int nodes, int min, int max);
        //BT functions:
        void expandExternal(const Position &p, int left=0, int right=0);
        //TODO: not implemented
        Position removeAboveExternal(const Position& p);
    protected:
        void preorder(node* v, PositionList& pl);
    };



} // BST

#endif //BINARYTREE_BST_H
