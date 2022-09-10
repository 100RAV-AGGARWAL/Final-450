/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    void inorder(Node* root, vector<int> &v) {
        if(!root) return;
        
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    void inorderToBST(Node* root, vector<int> v, int &i) {
        if(!root) return;
        
        inorderToBST(root->left, v, i);
        root->data = v[i];
        i++;
        inorderToBST(root->right, v, i);
    }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> v;
        inorder(root, v);
        
        sort(v.begin(), v.end());
        
        int i=0;
        inorderToBST(root, v, i);
        return root;
    }
};