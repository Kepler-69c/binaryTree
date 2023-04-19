// Created on 4/6/23.

#ifndef BINARYTREE_BT_H
#define BINARYTREE_BT_H

#include <iostream>

//En dehors des fonctions "insert()" et "random()", l'arbre de recherche binaire
// peut également être utilisé comme un arbre binaire normal. Exemple:
//
//BT binaryTree(1);
//binaryTree.expandExternal(binaryTree.root().left(), 2, NULL);
//binaryTree.printTree();

namespace BinaryTree {
    struct node {
    public:
        int data;
        node* left;
        node* right;
        node* parent;
        node(int d) : data(d), left(NULL), right(NULL), parent(NULL) {}
    };

    class BT {
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
        BT(int d);
        int size() const;
        bool isEmpty() const;
        int depth() const;
        Position root() const;
        PositionList positions() const;
        void addRoot(int d);
        //BT functions:
        void insertByValue(int d);
        void random(int nodes, int min, int max);
        void random(int nodes, int min, int max, bool insertByValue);
        //BT functions:
        void insertRandom(int d);
        int getFromDepth(int depth);
        void expandExternal(const Position &p, int left=0, int right=0);
        //TODO: not implemented
        Position removeAboveExternal(const Position& p);
    protected:
        void preorder(node* v, PositionList& pl);
    };



} // BT

#endif //BINARYTREE_BT_H
