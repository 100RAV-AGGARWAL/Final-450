/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
public:
    bool isLeaf(Node* root) {
        return (!root->left && !root->right);
    }
    
    void populateNextUtil(Node *root, Node* &suc) {
        if(!root) return;
        
        populateNextUtil(root->left, suc);
        
        if(suc) suc->next = root;
        suc = root;
        
        populateNextUtil(root->right, suc);
    }
    
    void populateNext(Node *root)
    {
        //code here
        Node* succ = NULL;
        populateNextUtil(root, succ);
    }
};