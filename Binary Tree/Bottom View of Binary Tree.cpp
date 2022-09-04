class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int, int> m;
        queue<pair<int, Node*>> q;
        
        if(!root) return ans;
        
        q.push({0, root});
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            Node *curr = p.second;
            
            m[p.first] = curr->data;
            
            if(curr->left) q.push({p.first-1, curr->left});
            if(curr->right) q.push({p.first+1, curr->right});
        }
        
        for(auto it:m) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};