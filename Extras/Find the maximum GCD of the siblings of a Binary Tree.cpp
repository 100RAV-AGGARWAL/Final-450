class Solution
{
public:
    int maxNode = 0, maxGcd = 0;

    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }

    void solve(Node *root)
    {
        if (!root)
            return;

        if (root->left && root->right)
        {
            int curr_gcd = gcd(root->left->data, root->right->data);

            if (curr_gcd == maxGcd)
            {
                maxNode = max(maxNode, root->data);
            }
            else if (curr_gcd > maxGcd)
            {
                maxNode = root->data;
                maxGcd = curr_gcd;
            }
        }

        if (root->left)
            solve(root->left);
        if (root->right)
            solve(root->right);
    }

    int maxGCD(Node *root)
    {
        solve(root);
        return maxNode;
    }
};