// Created: 3/30/23.

#include "iostream"
#include <stack>
#include <queue>
#include "treeSearch.h"
#include "BinaryTree.h"

using namespace std;
using namespace BinaryTree;

//depth-first search
void search::DFS(node* root) {
    search::DFS(root, -1000);
}

void search::DFS(node* root, int searchValue) {
    stack<node*> s;
    s.push(root);
    while (!s.empty()) {
        node* curr = s.top();
        s.pop();
        // do something with curr node
        if (curr->data == searchValue)
            return; //stop search if searchValue has been found
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

//breadth-first search
void search::BFS(node* root) {
    search::BFS(root, -1000);
}

void search::BFS(node* root, int searchValue) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* curr = q.front();
        q.pop();
        // do something with curr node
        if (curr->data == searchValue)
            return; //stop search if searchValue has been found
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