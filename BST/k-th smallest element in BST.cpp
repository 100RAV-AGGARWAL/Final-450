/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void util(Node* root, int &K, int &ans) {
        if(!root) return;
        
        if(K <= 0) return;
        
        util(root->left, K, ans);
        
        if(K > 0) {
            ans = root->data;
            K--;
        }
        
        util(root->right, K, ans);
    }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        int ans = -1;
        util(root, K, ans);
        
        if(K > 0) return -1;
        
        return ans;
    }
};