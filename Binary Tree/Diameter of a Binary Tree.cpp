/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    int height(struct Node* node){
        // code here 
        if(!node) return 0;
        
        int h = max(height(node->left), height(node->right));
        return h+1;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if(!root) return 0;
        
        int d = height(root->left) + height(root->right) + 1;
        
        return max(d, max(diameter(root->left), diameter(root->right)));
    }
};