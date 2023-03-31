#include <iostream>
#include "binaryTree/tree.h"
#include "treeSearch/treeSearch.h"

using namespace std;
using namespace tree;

int main() {
    BinaryTree bT;

    // Add root node with value 1
    bT.addRoot();
    BinaryTree::Position root_pos = bT.root();
    *root_pos = 1;

    cout << *root_pos << endl;

//     Expand root child nodes, set values for them
//    bT.expandExternal(root_pos.left());
//    bT.expandExternal(root_pos.right());
//    *root_pos.left() = 2;
//    *root_pos.right() = 3;
bT.expandExternal(root_pos);
*root_pos.left() = 2;
*root_pos.right() = 3;

bT.expandExternal(root_pos.left());
*root_pos.left().left() = 4;

cout << *root_pos.left().left() << endl;


//     depth-first search
    cout << "DFS traversal: " << endl;
    search::DFS(root_pos);
    cout << endl;

    return 0;
}
