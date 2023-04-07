#include "src/BinarySearchTree.h"
#include "src/treeSearch.h"

using namespace std;
using namespace BinarySearchTree;

int main() {
    int n = 10;
    BST tree(n);
    node* root_node = tree.root().v;

    tree.random(n, 1, n*2);
    tree.printTree();

    search::printTree(root_node);

    clock_t time0 = clock();
    // depth-first search
    search::DFS(root_node);
    clock_t time1 = clock();
    // breadth-first search
    search::BFS(root_node);
    clock_t time2 = clock();

    cout << "Time taken: (DFS) " << double(time1 - time0) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Time taken: (BFS) " << double(time2 - time1) / CLOCKS_PER_SEC << " seconds" << endl;


    return 0;
}
