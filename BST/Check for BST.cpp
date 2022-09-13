class Solution
{
    public:
    bool helper(Node* root, int mn, int mx) {
        if(!root) return true;
        
        if(root->data > mn && root->data < mx) {
            return helper(root->left, mn, root->data) && helper(root->right, root->data, mx);
        }
        
        return false;
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return helper(root, INT_MIN, INT_MAX);
    }
};