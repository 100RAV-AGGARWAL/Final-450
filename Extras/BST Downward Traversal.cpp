class Solution{
public:
    bool flag = false;
    long long int sum = 0, targetPos;
    Node *tar = NULL;
    
    void dfs(Node *root, int target, int pos) {
        if(!root) return;
        
        if(root->data == target && !flag) {
            targetPos = pos;
            tar = root;
            return;
        } 
        
        dfs(root->left, target, pos-1);
        dfs(root->right, target, pos+1);
        
        if(flag) {
            if(pos == targetPos) sum += root->data;
        }
        
    }
    
    long long int verticallyDownBST(Node *root,int target){
        // Code here
        dfs(root, target, 0);
        flag = true;
        
        if(tar == NULL) return -1;
        dfs(tar, target, targetPos);
        return sum - tar->data;
    }
};