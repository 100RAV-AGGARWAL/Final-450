#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left
   child and a pointer to right child */
struct Node {
    int data;
    Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
/* This function is here just to test  */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

Node* treeFromString(string str) {
    int n = str.length();
    if(n == 0) return NULL;

    Node *root = newNode(str[0]-'0');
    Node *curr = root;
    stack<Node*> st;

    for(int i=1; i<n; i++) {
        if(str[i] == '(') {
            st.push(curr);
        } else if(str[i] == ')') {
            Node *n = st.top();
            st.pop();

            if(!n->left) n->left = curr;
            else n->right = curr;

            curr = n;
        } else {
            Node *n = newNode(str[i]-'0');
            curr = n;
        }
    }

    return root;

}


// Driver Code
int main()
{
    string str = "4(2(3)(1))(6(5(8)))";
    Node* root = treeFromString(str);
    preOrder(root);
}