// User function template for C++

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    bool isLeaf(Node *node)
    {
        return (node && !node->left && !node->right);
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        if (!node)
            return;

        if (isLeaf(node))
        {
            node->data = 0;
            return;
        }

        int sum = (node->left ? node->left->data : 0) + (node->right ? node->right->data : 0);

        toSumTree(node->right);
        toSumTree(node->left);

        sum += (node->left ? node->left->data : 0) + (node->right ? node->right->data : 0);

        node->data = sum;
        return;
    }
};