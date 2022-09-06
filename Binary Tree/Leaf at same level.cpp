/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    bool isLeaf(Node* root) {
        return (!root->left && !root->right);    
    }
    
    bool check(Node *root)
    {
        //Your code here
        if(!root) return true;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        int level = 0, temp=-1;
        
        map<Node*, int> m;
        
        while(!q.empty()) {
            Node *front = q.front();
            q.pop();
            
            if(front) {
                if(isLeaf(front)) {
                    m[front] = level;
                    if(temp == -1)
                        temp = level;
                    else if(temp != level) return false;
                }
                if(front->left) q.push(front->left); 
                if(front->right) q.push(front->right);
            }
            else {
                if(!q.empty()) {
                    level++;
                    q.push(NULL);
                }
            }
        }
        
        return true;
        
    }
};