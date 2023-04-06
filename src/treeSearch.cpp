// Created: 3/30/23.

#include "iostream"
#include "treeSearch.h"
#include "tree.h"

using namespace std;

// depth-first search
void search::DFS(BinaryTree::Position pos) {
    if (!pos.isExternal()) {
        cout << *pos << " "; // Visit the current node
        // Recursively visit left and right subtrees
        search::DFS(pos.left());
        search::DFS(pos.right());
    }
}
