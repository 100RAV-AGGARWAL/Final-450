/*You are required to complete below method */
bool isLeaf(Node* root) {
    return (!root->left && !root->right);
}

bool util(Node* root, int low, int high) {
    if(!root) return false;
    
    if(isLeaf(root)) {
        if(root->data == low && root->data == high) return true;
        return false;
    }
    
    bool lAns = util(root->left, low, root->data-1);
    bool rAns = util(root->right, root->data+1, high);
    
    return lAns || rAns;
}

bool isDeadEnd(Node *root)
{
    //Your code here
    return util(root, 1, INT_MAX);
}