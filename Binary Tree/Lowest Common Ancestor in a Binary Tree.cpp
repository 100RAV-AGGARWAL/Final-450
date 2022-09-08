/* A binary tree node

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

class Solution
{
    public:
    bool ancestor(Node* root, int child, vector<Node*> &v) {
        if(!root) return false;
        
        if(root->data == child) {
            v.push_back(root);
            return true;
        }
        
        bool lFlag = ancestor(root->left, child, v);
        
        if(lFlag) {
            v.push_back(root);
            return true;
        }
        
        bool rFlag = ancestor(root->right, child, v);
        
        if(rFlag) {
            v.push_back(root);
            return true;
        }
        
        return false;
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
       vector<Node*> a1, a2;
       
       bool n1flag = ancestor(root, n1, a1);
       bool n2flag = ancestor(root, n2, a2);
       
       if(!n1flag && !n2flag) return NULL;
       
       for(auto node : a1) {
           if(find(a2.begin(), a2.end(), node) != a2.end()) return node;
       }
       return NULL;
    }
};