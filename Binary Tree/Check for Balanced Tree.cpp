/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    int checker(Node* node, bool &flag){
        // code here 
        if(!node || !flag) return 0;
        
        int left = checker(node->left, flag);
        int right = checker(node->right, flag);
        
        if(abs(left-right) > 1) flag = false;
        int h = max(left, right);
        return h+1;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(!root) return true;
        
        bool flag = true;
        int ans = checker(root, flag);
        return flag;
    }
};