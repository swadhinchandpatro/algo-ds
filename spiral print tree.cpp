// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
};

Node* newNode(int val) {
    Node* node = new Node();
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int depth = 0; 
void printLevel(Node* root, int level, int treeLevel, int dir) {
    if(root == NULL) return;
    if(level == 1) {
        cout<<root->val<<" ";
        if(depth +1 == treeLevel) {
            depth++;
        }
        return;
    }
    if(dir) {
        printLevel(root->left, level - 1, treeLevel, dir);
        printLevel(root->right, level - 1, treeLevel, dir);
    } else {
        printLevel(root->right, level - 1, treeLevel, dir);
        printLevel(root->left, level - 1, treeLevel, dir);
    }
}

void traverse(Node* root) {
    if(root == NULL) {
        return;
    }
    int level = 1;
    while(depth + 1 == level) {
        printLevel(root, level, level, level%2);
        level++;
    }
}
int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(7);
    root->right->right->left = newNode(8);
    traverse(root);
    return 0;
}