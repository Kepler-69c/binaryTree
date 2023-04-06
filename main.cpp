#include <iostream>
//#include "src/tree.h"
//#include "src/treeSearch.h"
#include "src/BinarySearchTree.h"

using namespace std;
using namespace BinarySearchTree;
//using namespace tree;

int main() {
//    BinaryTree bT;
//
//    // Add root node with value 1
//    bT.addRoot();
//    BinaryTree::Position root_pos = bT.root();
//    *root_pos = 1;
//
//    cout << *root_pos << endl;
//
//    bT.expandExternal(root_pos);
//    *root_pos.left() = 2;
//    *root_pos.right() = 3;
//
//    bT.expandExternal(root_pos.left());
//    bT.expandExternal(root_pos.right());
//    *root_pos.left().left() = 4;
//    *root_pos.left().right() = 5;
//
//    cout << *root_pos.left().left() << endl;
//
//
////     depth-first search
//    cout << "DFS traversal: " << endl;
//    search::DFS(root_pos);
//    cout << endl;

    BST tree(2);
    BST::Position root = tree.root();
//    cout << *root << endl;
    tree.insert(3);
    tree.insert(0);
    tree.insert(4);
    tree.insert(3);
    tree.printTree();

    srand(time(0));
    for (int i = 0; i < 40; i++)
        tree.insert(rand() % 100);

    tree.printTree();

    return 0;
}
