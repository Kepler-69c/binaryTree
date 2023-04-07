#include "src/BinarySearchTree.h"

using namespace std;
using namespace BinarySearchTree;

int main() {
    BST tree(2);
    tree.random(40, 1, 100);
    tree.printTree();

    return 0;
}
