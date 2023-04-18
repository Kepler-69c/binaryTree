#include <fstream>
#include "src/BinarySearchTree.h"
#include "src/treeSearch.h"

using namespace std;
using namespace BinarySearchTree;

void repetition(int nodes, int repetition, int startDepth, BST tree, node* root) {
    ofstream csv;
    csv.open ("example.csv");
    csv << "Nodes: " << nodes << ", Search: DFS\n";

    for (int j = startDepth; j < tree.depth()-1; ++j) {
        csv << "Depth " << j << ":," << j << ",";
        cout << "Depth " << j << endl;

        for (int i = 0; i < repetition; ++i) {
            int searchValue = tree.getFromDepth(j);
            cout << "Gesuchter Wert:    " << searchValue << endl;

            clock_t time0 = clock();
            search::BFS(root, searchValue);
            clock_t time1 = clock();
            csv << double(time1 - time0) / CLOCKS_PER_SEC << ",";
        }
        csv << "\n";
    }
    csv.close();
}

void comparison(int depth, BST tree, node* root) {
    int searchValue = tree.getFromDepth(depth);
    cout << "Gesuchter Wert:    " << searchValue << endl;

    clock_t time0 = clock();
    // depth-first search
    search::DFS(root, searchValue);
    clock_t time1 = clock();
    // breadth-first search
    search::BFS(root, searchValue);
    clock_t time2 = clock();

    cout << "Time taken: (DFS)  " << double(time1 - time0) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Time taken: (BFS)  " << double(time2 - time1) / CLOCKS_PER_SEC << " seconds" << endl;
}

int main() {
    int n = 1000000;
    int searchDepth = 4;
    int repeating = 10;
    BST tree(n);
    node* root_node = tree.root().v;

    clock_t time0 = clock();
    tree.random(n, 1, n*2);
    clock_t time1 = clock();
    cout << "Time taken: (Tree) " << double(time1 - time0) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Maximum tree depth " << tree.depth() << endl;
//    search::printTree(root_node);

//    comparison(searchDepth, tree, root_node);
    repetition(n, repeating, 1, tree, root_node);

    return 0;
}
