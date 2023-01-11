class Solution
{
public:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
    };

    struct cmp
    {
        bool operator()(Node *l, Node *r)
        {
            return (l->data > r->data);
        }
    };

    void preOrder(Node *root, string s, vector<string> &ans)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            ans.push_back(s);
            return;
        }

        preOrder(root->left, s + "0", ans);
        preOrder(root->right, s + "1", ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Code here
        priority_queue<Node *, vector<Node *>, cmp> pq;

        for (int i = 0; i < N; i++)
        {
            pq.push(new Node(f[i]));
        }

        while (pq.size() != 1)
        {
            Node *l = pq.top();
            pq.pop();

            Node *r = pq.top();
            pq.pop();

            Node *parent = new Node(l->data + r->data);
            parent->left = l;
            parent->right = r;

            pq.push(parent);
        }

        Node *root = pq.top();
        pq.pop();
        vector<string> ans;
        preOrder(root, "", ans);

        return ans;
    }
};