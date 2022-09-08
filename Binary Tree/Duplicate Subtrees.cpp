string util(Node* root, vector<Node*> &ans, map<string, int> &m) {
    if(!root) return "#";
    
    string s = to_string(root->data) + " " + util(root->left, ans, m) + " " + util(root->right, ans, m);
    if(m[s] == 1) ans.push_back(root);
    m[s]++;
    return s;
}

vector<Node*> printAllDups(Node* root)
{
    // Code here
    vector<Node*> ans;
    map<string, int> m;
    util(root, ans, m);
    return ans;
}