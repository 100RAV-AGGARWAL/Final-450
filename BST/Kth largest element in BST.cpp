/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    void inorder(Node* root, vector<int> &v) {
        if(!root) return;
    
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> v;
        inorder(root, v);
        
        if(K > v.size()) return -1;
        
        return v[v.size()-K];
    }
};