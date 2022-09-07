
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

int maxSumUtil(Node* root, int &maxSum) {
    if(!root) return 0;
    if(isLeaf(root)) {
        maxSum = max(maxSum, root->data);
    }

    int lSum = maxSumUtil(root->left, maxSum);
    int rSum = maxSumUtil(root->right, maxSum);

    int s = root->data + lSum + rSum;
    maxSum = max(maxSum, s);

    return s;
}

// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
    int maxSum = INT_MIN;

    if(!root) return maxSum;
    
    int sum = maxSumUtil(root, maxSum);
    return maxSum;
}
 
// Driver function
int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
 
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
 
    cout << findLargestSubtreeSum(root);
    return 0;
}