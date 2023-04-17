// Created: 3/30/23.

#include "iostream"
#include <stack>
#include <queue>
#include "treeSearch.h"
#include "BinarySearchTree.h"

using namespace std;
using namespace BinarySearchTree;

//depth-first search
void search::DFS(node* root) {
    stack<node*> s;
    s.push(root);
    while (!s.empty()) {
        node* curr = s.top();
        s.pop();
        // do something with curr node
//        cout << curr->data << " ";
        if (curr->right != nullptr) {
            s.push(curr->right);
        }
        if (curr->left != nullptr) {
            s.push(curr->left);
        }
    }
    cout << endl;
}

//bre
void search::BFS(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* curr = q.front();
        q.pop();
        // do something with curr node
//        cout << curr->data << " ";
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

void search::printTree(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            node* curr = q.front();
            q.pop();
            if (curr != nullptr) {
                cout << curr->data << " ";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                cout << "N ";
            }
        }
        cout << endl;
    }
}