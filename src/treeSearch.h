// Created: 3/30/23.
#pragma once
#ifndef BINARYTREE_TREESEARCH_H
#define BINARYTREE_TREESEARCH_H

#include "iostream"
#include "BinaryTree.h"

using namespace std;
using namespace BinaryTree;

// various tree search algorithms
namespace search {
    void DFS(node* root);
    void DFS(node* root, int searchValue);
    void BFS(node* root);
    void BFS(node* root, int searchValue);
    void printTree(node* root);
}


#endif //BINARYTREE_TREESEARCH_H
