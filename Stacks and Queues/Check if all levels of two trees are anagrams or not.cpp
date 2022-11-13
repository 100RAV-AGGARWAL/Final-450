class Solution{
    public:
    int height(Node* node){
        // code here 
        if(!node) return 0;
        
        int h = max(height(node->left), height(node->right));
        return h+1;
    }
    
    bool areAnagrams(Node *root1, Node *root2)
    {
        queue<pair<Node*,int>> q1, q2;
        
        if(root1->data != root2->data) return false;
        
        q1.push({root1, 0});
        q2.push({root2, 0});
        
        int h1 = height(root1);
        int h2 = height(root2);
        
        if(h1 != h2) return false;
        
        vector<string> v1(h1), v2(h2);
        
        while(!q1.empty() && !q2.empty()) {
            
            auto r1 = q1.front();
            auto r2 = q2.front();
            q1.pop();
            q2.pop();
            
            v1[r1.second] += r1.first->data;
            v2[r2.second] += r2.first->data;
            
            if(r1.first->left) q1.push({r1.first->left, r1.second+1});
            if(r1.first->right) q1.push({r1.first->right, r1.second+1});
            
            if(r2.first->left) q2.push({r2.first->left, r2.second+1});
            if(r2.first->right) q2.push({r2.first->right, r2.second+1});
        }
        
        for(int i=1; i<v1.size(); i++) {
            reverse(v1[i].begin(), v1[i].end());
            
            if(v1[i] != v2[i]) return false;
        }
        
        return true;
    }
};