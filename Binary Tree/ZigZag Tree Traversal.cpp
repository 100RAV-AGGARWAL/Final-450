/*Structure of the node of the binary tree is as
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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
        
        if(!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        int level = 0;
        while(!q.empty()) {
            int s = q.size();
            vector<int> temp;
            
            for(int i=0; i<s; i++) {
                Node *top = q.front();
                q.pop();
                temp.push_back(top->data);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            
            level++;
            if(level % 2 == 0) reverse(temp.begin(), temp.end());
            
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        
        return ans;
    }
};