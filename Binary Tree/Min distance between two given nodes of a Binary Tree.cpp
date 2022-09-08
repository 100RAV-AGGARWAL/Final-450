/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    Node* lca(Node* root, int a, int b) {
        if(!root) return NULL;
        if(root->data == a || root->data == b) return root;
        
        Node *l = lca(root->left, a, b);
        Node *r = lca(root->right, a, b);
        
        if(!l) return r;
        else if(!r) return l;
        
        return root;
    }
    
    void distance(Node* node, int dist, int &ans, int data) {
        if(!node) return;
        
        if(node->data == data) {
            ans = dist;
            return;
        }
        
        distance(node->left, dist+1, ans, data);
        distance(node->right, dist+1, ans, data);
    }
    
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        int ans=0;
        Node* anc = lca(root, a, b);
        int dist1 = 0, dist2 = 0;
        distance(anc, 0, dist1, a);
        distance(anc, 0, dist2, b);
        
        return dist1+dist2;
    }
};