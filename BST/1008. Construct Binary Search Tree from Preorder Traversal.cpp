/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        
        TreeNode *n = new TreeNode(preorder[0]);
        
        auto start = preorder.begin()+1, end = upper_bound(preorder.begin(), preorder.end(), preorder[0]);        
        vector<int> l(start, end), e(end, preorder.end());
        
        
        n->left = bstFromPreorder(l);
        n->right = bstFromPreorder(e);
        
        return n;
        
    }
};