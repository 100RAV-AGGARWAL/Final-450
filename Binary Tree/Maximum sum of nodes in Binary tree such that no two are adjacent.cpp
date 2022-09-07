
// C++ program to find largest subtree
// sum in a given binary tree.
#include <bits/stdc++.h>
using namespace std;
 
// Structure of a tree node.
struct Node {
    int data;
    Node *left, *right;
};
 
// Function to create new tree node.
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

bool isLeaf(Node *root) {
    if(!root->left && !root->right) return true;
    return false;
}

int maxSumUtil(Node* root, map<Node*, int> &m);

int sumOfGrandChildren(Node* root, map<Node*, int> &m) {
    if(!root) return 0;

    int sum = 0;

    if(root->left) sum += maxSumUtil(root->left->left, m) + maxSumUtil(root->left->right, m);
    if(root->right) sum += maxSumUtil(root->right->left, m) + maxSumUtil(root->right->right, m);

    return sum;
    
}

int maxSumUtil(Node* root, map<Node*, int> &m) {
    if(!root) return 0;
    
    if(m.find(root) != m.end()) return m[root];

    int incl = root->data + sumOfGrandChildren(root, m);
    int excl = maxSumUtil(root->left, m) + maxSumUtil(root->right, m);

    int s = max(incl, excl);
    m[root] = s;

    return s;
}

// Function to find largest subtree sum.
int getMaxSum(Node* root)
{
    if(!root) return 0;
    map<Node*, int> m;
    int sum = maxSumUtil(root, m);
    return sum;
}
 
// Driver function
int main()
{
    /*
               1
             /   \
            /     \
           2       3
          /       /  \
         /       /    \
        1       4      5
    */
 
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(8);
    root->right->right = newNode(5);
    root->right->left = newNode(4);
 
    cout << getMaxSum(root);
    return 0;
}