class Solution
{
public:
    int util(Node *root, int &mx)
    {
        if (!root)
        {
            return INT_MIN;
        }

        int left = util(root->left, mx);
        int right = util(root->right, mx);
        int main = root->data;

        if (left != INT_MIN)
            main += left;
        if (right != INT_MIN)
            main += right;

        mx = max(mx, max(main, max(left, right)));

        return main;
    }

    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node *root)
    {
        // Write your code here
        int mx = INT_MIN;

        int ans = util(root, mx);

        return mx;
    }
};