// Created: 3/30/23.

#ifndef BINARYTREE_TREESEARCH_H
#define BINARYTREE_TREESEARCH_H

#include "iostream"
#include "BinarySearchTree.h"

using namespace std;
using namespace BinarySearchTree;

// various tree search algorithms
namespace search {
    void DFS(node* root);
    void BFS(node* root);
    void printTree(node* root);
}


#endif //BINARYTREE_TREESEARCH_H
