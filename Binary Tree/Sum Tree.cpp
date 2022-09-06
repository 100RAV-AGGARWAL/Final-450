/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    bool isLeaf(Node* root) {
        return (!root->left && !root->right);    
    }
    
    int calcSum(Node* root) {
        if(!root) return 0;
        
        return root->data + calcSum(root->left) + calcSum(root->right);
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         if(!root) return true;
         
         if(isLeaf(root)) return true;
         
         int lSum = 0, rSum=0;
         
         if(root->left) {
             if(root->data < root->left->data) return false;
             else 
                lSum = calcSum(root->left);
         }
         
         if(root->right) {
             if(root->data < root->right->data) return false;
             else 
                rSum = calcSum(root->right);
         }
         
         if(root->data == lSum+rSum) {
             return (isSumTree(root->left) && isSumTree(root->right));
         } else
            return false;
    }
};