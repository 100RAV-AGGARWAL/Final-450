/* Structure for tree and linked list

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

// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        if(!root) return NULL;
        
        Node *l = bToDLL(root->left);
        Node *r = bToDLL(root->right);
        
        root->right = r;
        if(r) r->left = root;
        
        if(l) {
            Node *curr = l;
            while(curr->right) {
                curr = curr->right;
            }
            
            curr->right = root;
            root->left = curr;
        } else {
            root->left = NULL;
            return root;
        }
        
        return l;
    }
};