
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

void printVect(vector<int> v, int k) {
    for(int i=k; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void kSumPath(Node* root, int k, vector<int> &path) {

    if(!root) return;

    path.push_back(root->data);

    kSumPath(root->left, k, path);
    kSumPath(root->right, k, path);

    int sum = 0;
    for(int i=path.size()-1; i>=0; i--) {
        sum += path[i];

        if(sum == k) {
            printVect(path, i);
        }
    }
    path.pop_back();

}
 
// Driver function
int main()
{
    /*
               1
             /   \
            /     \
           -1       0
          /       /  \
         /       /    \
        2       1      5
    */
 
    Node* root = newNode(1);
    root->left = newNode(-1);
    root->right = newNode(0);
    root->left->left = newNode(2);
    root->right->right = newNode(5);
    root->right->left = newNode(1);
 
    vector<int> path;
    kSumPath(root, 2, path);

    return 0;
}