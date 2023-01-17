map<Node *, int> mp;

int LISS(Node *root)
{
    // Code here
    if (!root)
        return 0;

    if (mp.find(root) != mp.end())
        return mp[root];

    int take = 0, nottake = 0;

    int takeleft = 0, takeright = 0;

    if (root->left)
    {
        takeleft = LISS(root->left->left) + LISS(root->left->right);
    }

    if (root->right)
    {
        takeright = LISS(root->right->left) + LISS(root->right->right);
    }

    take = 1 + takeleft + takeright;

    nottake = LISS(root->left) + LISS(root->right);

    return mp[root] = max(take, nottake);
}