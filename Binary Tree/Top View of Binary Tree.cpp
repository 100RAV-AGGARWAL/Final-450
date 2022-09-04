/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int, int> m;
        queue<pair<int, Node*>> q;
        
        if(!root) return ans;
        
        q.push({0, root});
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            Node *curr = p.second;
            
            if(m.find(p.first) == m.end()) m[p.first] = curr->data;
            
            if(curr->left) q.push({p.first-1, curr->left});
            if(curr->right) q.push({p.first+1, curr->right});
        }
        
        for(auto it:m) {
            ans.push_back(it.second);
        }
        
        return ans;
    }

};