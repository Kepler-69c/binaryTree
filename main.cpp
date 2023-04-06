#include <iostream>
#include <functional>
#include "src/BinarySearchTree.h"

using namespace std;
using namespace BinarySearchTree;

int main() {
    BST tree(2);
//
//    srand(time(0));
//    for (int i = 0; i < 40; i++)
//        tree.insert(rand() % 100);

    tree.random(40, 1, 100);
    tree.printTree();

    return 0;
}
