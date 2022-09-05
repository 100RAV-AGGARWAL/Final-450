/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node *root) {
        if(!root->left && !root->right) return true;
        return false;
    }
    
    void addLeaf(Node *root, vector<int> &ans) {
        if(isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left) addLeaf(root->left, ans);
        if(root->right) addLeaf(root->right, ans);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(!root) return ans;
        
        ans.push_back(root->data);
        
        if(isLeaf(root)) {
           return ans; 
        }
        
        //Left
        Node *curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) {
                ans.push_back(curr->data);
            }
            
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
        
        //Leaf
        addLeaf(root, ans);
        
        //Right
        stack<int> st;
        curr = root->right;
        while(curr) {
            if(!isLeaf(curr)) st.push(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};