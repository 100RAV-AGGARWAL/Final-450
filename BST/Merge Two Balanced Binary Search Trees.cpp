// C++ program to convert a left unbalanced BST to
// a balanced BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

bool comp(pair<int, Node*> p1, pair<int, Node*> p2) {
    return p1.first < p2.first;
}

void inorder(Node* root, vector<pair<int, Node*>> &v) {
    if(!root) return;

    inorder(root->left, v);
    v.push_back({root->data, root});
    inorder(root->right, v);
}

Node* util(vector<pair<int,Node*>> v, int st, int en) {
	if(st > en) return NULL;

	int mid = (st+en)/2;

	Node *n = v[mid].second;
	n->left = util(v, st, mid-1);
	n->right = util(v, mid+1, en);
	return n;
}

Node* mergeTwoBST(Node* root1, Node* root2)
{
    vector<pair<int, Node*>> v;
	inorder(root1, v);
	inorder(root2, v);

    sort(v.begin(), v.end(), comp);

	int len = v.size();
	return util(v, 0, len-1);

}

void printInorder(Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Utility function to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Driver program
int main()
{
/* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    Node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
 
    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    Node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);
 
    Node *mergedTree = mergeTwoBST(root1, root2);
 
    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);
 
    return 0;
}
