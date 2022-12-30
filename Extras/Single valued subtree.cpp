/* Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

class Solution
{
public:
    int cnt = 0;
    bool isLeaf(Node *root)
    {
        return (root && !root->left && !root->right);
    }

    bool isSingleValued(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        bool left = isSingleValued(root->left), right = isSingleValued(root->right);

        if (!left || !right)
            return false;

        if (root->left && root->data != root->left->data)
        {
            return false;
        }

        if (root->right && root->data != root->right->data)
        {
            return false;
        }

        cnt++;
        return true;
    }

    int singlevalued(Node *root)
    {
        bool t = isSingleValued(root);
        return cnt;
    }
};