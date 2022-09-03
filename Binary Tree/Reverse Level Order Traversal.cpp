/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    if (!root)
        return {};

    vector<int> ans;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();

        ans.push_back(n->data);

        if (n->right)
            q.push(n->right);
        if (n->left)
            q.push(n->left);
    }

    reverse(ans.begin(), ans.end());
    
    return ans;
}