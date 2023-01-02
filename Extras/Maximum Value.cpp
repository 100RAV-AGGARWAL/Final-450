// User function Template for C++
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution
{
public:
    vector<int> maximumValue(Node *node)
    {
        // code here
        vector<int> ans;
        queue<Node *> q;

        if (!node)
            return ans;

        q.push(node);

        while (!q.empty())
        {
            int n = q.size();
            priority_queue<int> pq;

            for (int i = 0; i < n; i++)
            {
                auto f = q.front();
                q.pop();

                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);

                pq.push(f->data);
            }

            ans.push_back(pq.top());
        }

        return ans;
    }
};