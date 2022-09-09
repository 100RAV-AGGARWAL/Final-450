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
    bool isLeaf(TreeNode* root) {
        return (!root->left && !root->right);    
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(root->val == key) {
            if(isLeaf(root)) return NULL;
            else {
                if(root->left) {
                    TreeNode *l = root->left;
                    TreeNode *r = root->right;
                    
                    while(l->right) l = l->right;
                    
                    l->right = r;
                    l = root->left;
                    root->right = NULL;
                    root->left = NULL;
                    delete(root);
                    return l;
                } else if(root->right) {
                    TreeNode *l = root->left;
                    TreeNode *r = root->right;
                    
                    while(r->left) r = r->left;
                    
                    r->left = l;
                    r = root->right;
                    root->right = NULL;
                    root->left = NULL;
                    delete(root);
                    return r;
                }
            }
        }
        
        if(key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        
        return root;
    }
};