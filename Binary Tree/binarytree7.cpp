#include <bits/stdc++.h>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to perform preorder traversal on the tree
void preorderRecursive(Node* root)
{
    // if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
 
    // Traverse the left subtree
    preorderRecursive(root->left);
 
    // Traverse the right subtree
    preorderRecursive(root->right);
}

void preorderIterative(Node* root) {
	stack<Node*> st;
	st.push(root);

	while(!st.empty()) {
		Node *curr = st.top();
		st.pop();

		cout<<curr->data<<" ";

		if(curr->right) {
			st.push(curr->right);
		} 
		if(curr->left) { 
			st.push(curr->left);
		}
	}
}
 
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    preorderRecursive(root);
	cout<<endl;
	preorderIterative(root);
 
    return 0;
}