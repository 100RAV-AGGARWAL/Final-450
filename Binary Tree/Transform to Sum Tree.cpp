/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    bool isLeaf(Node *root) {
        if(!root->left && !root->right) return true;
        return false;
    }
    
    int calcSum(Node *root) {
        if(!root) return 0;
        
        return root->data + calcSum(root->left) + calcSum(root->right);
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        if(!node) return;
        
        node->data = calcSum(node->left) + calcSum(node->right);
        
        toSumTree(node->left);
        toSumTree(node->right);
    }
};