#include <iostream>
#include "binaryTree/tree.h"

using namespace std;
using namespace tree;

int main() {
    BinaryTree bT;

    // is the tree initialised?
    cout << bT.isEmpty() << endl;

    // Add root node with value 1
    bT.addRoot();
    BinaryTree::Position root_pos = bT.root();
    *root_pos = 1;

    // Expand root child nodes, set values for them
    bT.expandExternal(root_pos.left());
    bT.expandExternal(root_pos.right());
    *root_pos.left() = 2;
    *root_pos.right() = 3;

    return 0;
}
