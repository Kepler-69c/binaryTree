#include <fstream>
#include<list>
#include "src/BinarySearchTree.h"
#include "src/treeSearch.h"

using namespace std;
using namespace BinarySearchTree;

void repetitionDepth(int nodes, int repetition, int startDepth, BST tree, node* root) {
    ofstream csv;
    csv.open ("data.csv");
    csv << "Nodes: " << nodes << ", Search: BFS\n";

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

void repetitionSize(int repeating, int startNodes, int growth) {
    ofstream csv;
    csv.open ("data.csv");
    csv << "StartNodes: " << startNodes << ", growth:" << growth << ", Search: DFS\n";

//    for (int nodes = startNodes; nodes < 5000000; nodes = nodes * growFactor) { // 5 million is the max tree size for my pc
    for (int nodes = startNodes; nodes < 5000001; nodes = nodes + growth) {
        // create tree
        BST tree(nodes);
        node* root_node = tree.root().v;
        tree.random(nodes, 1, nodes*2);
        cout << "Node number: " << nodes << endl;

        csv << "Size " << nodes << ":," << nodes << ",";
        cout << "Size " << nodes << endl;

        // repeat tree search n times
        for (int i = 0; i < repeating; ++i) {
            int searchValue = tree.getFromDepth(tree.depth());
            cout << "Gesuchter Wert:    " << searchValue << endl;

            clock_t time0 = clock();
            search::DFS(root_node, searchValue);
            clock_t time1 = clock();
            csv << double(time1 - time0) / CLOCKS_PER_SEC << ",";
        }
        csv << "\n";
        delete root_node;
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
    // comparison
    int searchDepth = 4;
    int n = 5000000;

    // repetition
    int repeating = 100;
    int startNodes = 1000; //10
    int growFactor = 10;
    int growAddend = 100000;

    BST tree(n);
    node* root_node = tree.root().v;

    clock_t time0 = clock();
    tree.random(n, 1, n*2);
    clock_t time1 = clock();
    cout << "Time taken: (Tree) " << double(time1 - time0) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Maximum tree depth " << tree.depth() << endl;
//    search::printTree(root_node);

//    comparison(searchDepth, tree, root_node);
//    repetitionDepth(n, repeating, 1, tree, root_node);
    repetitionSize(repeating, startNodes, growAddend);

    return 0;
}
