/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
public:
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *node)
    {
        // Your code here
        if (!node)
            return {};

        vector<int> ans;
        queue<Node *> q;

        q.push(node);

        while (!q.empty())
        {
            Node *root = q.front();
            q.pop();

            ans.push_back(root->data);

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }

        return ans;
    }
};