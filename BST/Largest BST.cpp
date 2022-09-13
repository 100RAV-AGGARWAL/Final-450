/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    int ans;
    pair<int, pair<int, int>> util(Node* root) {
        if(!root) return {0, {INT_MAX, INT_MIN}};
        
        auto l = util(root->left);
        auto r = util(root->right);
        
        if(root->data > l.second.second && root->data < r.second.first && l.first != -1 && r.first != -1) {
            int size = l.first + r.first + 1;
            ans = max(ans, size);
            return {size, {min(root->data, l.second.first), max(root->data, r.second.second)}}; 
        }
        
        return {-1, {INT_MAX, INT_MIN}};
        
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	ans = 0;
    	util(root);
    	return ans;
    	
    }
};