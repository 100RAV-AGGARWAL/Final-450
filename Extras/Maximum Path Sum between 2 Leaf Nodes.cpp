class Solution
{
public:
    int mx = INT_MIN;
    int findMaxPathSum(Node *root)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return root->data;

        int left = findMaxPathSum(root->left);
        int right = findMaxPathSum(root->right);

        if (!root->left)
            return right + root->data;
        if (!root->right)
            return left + root->data;

        mx = max(mx, root->data + left + right);

        return max(root->data + left, root->data + right);
    }

    int maxPathSum(Node *root)
    {
        int ans = findMaxPathSum(root);

        if (!root->left || !root->right)
            mx = max(mx, ans);

        return mx;
    }
};