// C++ program to convert a left unbalanced BST to
// a balanced BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

void inorder(Node* root, vector<Node*> &v) {
    if(!root) return;

    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}

Node* util(vector<Node*> v, int st, int en) {
	if(st > en) return NULL;

	int mid = (st+en)/2;

	Node *n = v[mid];
	n->left = util(v, st, mid-1);
	n->right = util(v, mid+1, en);
	return n;
}

Node* buildTree(Node* root)
{
    vector<Node*> v;
	inorder(root, v);

	int len = v.size();
	return util(v, 0, len-1);

}

// Utility function to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// Driver program
int main()
{
	/* Constructed skewed binary tree is
				10
			/
			8
			/
			7
		/
		6
		/
		5 */

	Node* root = newNode(10);
	root->left = newNode(8);
	root->left->left = newNode(7);
	root->left->left->left = newNode(6);
	root->left->left->left->left = newNode(5);

	root = buildTree(root);

	printf("Preorder traversal of balanced "
			"BST is : \n");
	preOrder(root);

	return 0;
}
