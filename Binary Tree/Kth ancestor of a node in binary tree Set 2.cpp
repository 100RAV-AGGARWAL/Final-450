/* C++ program to calculate Kth ancestor of given node */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

bool ancestor(Node* root, int child, vector<Node*> &v) {
    if(!root) return false;
    
    if(root->data == child) {
        v.push_back(root);
        return true;
    }
    
    bool lFlag = ancestor(root->left, child, v);
    
    if(lFlag) {
        v.push_back(root);
        return true;
    }
    
    bool rFlag = ancestor(root->right, child, v);
    
    if(rFlag) {
        v.push_back(root);
        return true;
    }
    
    return false;
}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	int k = 3;
	int node = 5;

	// print kth ancestor of given node
    vector<Node*> v = {};
    bool ans = ancestor(root, node, v);

	if (!ans)
		cout << "-1";
    else {
        if(k >= v.size()) cout<<"-1";
        else cout<<v[k]->data;
    }
	
	return 0;
}
