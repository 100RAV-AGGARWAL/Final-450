/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    bool isLeaf(Node *root) {
        if(!root->left && !root->right) return true;
        return false;
    }
    
    int height(Node* root, int &sum) {
        if(!root) return 0;
        if(isLeaf(root)) {
            sum += root->data;
            return 1;
        }
        
        int lSum=root->data, rSum=root->data;
        
        int lh = height(root->left, lSum);
        int rh = height(root->right, rSum);
        
        if(lh > rh){
            sum += lSum;
        }
        else if(lh < rh) {
            sum += rSum;
        }
        else sum += max(lSum, rSum);
        
        return max(lh, rh)+1;
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int s = 0;
        int h = height(root, s);
        
        return s;
    }
};