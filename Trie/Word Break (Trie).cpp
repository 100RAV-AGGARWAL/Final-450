struct TrieNode
{
    bool isLeaf;
    TrieNode *children[26];

    TrieNode()
    {
        isLeaf = false;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Solution
{
public:
    // A : given string to search
    // B : vector of available strings
    void insert(TrieNode *root, string key)
    {
        TrieNode *node = root;

        for (auto i : key)
        {
            if (node->children[i - 'a'] == NULL)
            {
                node->children[i - 'a'] = new TrieNode();
            }

            node = node->children[i - 'a'];
        }

        node->isLeaf = true;
    }

    bool search(TrieNode *root, string key)
    {
        TrieNode *node = root;

        for (auto i : key)
        {
            if (node->children[i - 'a'] == NULL)
            {
                return false;
            }

            node = node->children[i - 'a'];
        }

        return node->isLeaf;
    }

    int util(string A, TrieNode *root)
    {
        int n = A.length();

        if (n == 0)
            return 1;

        for (int i = 1; i <= n; i++)
        {
            if (search(root, A.substr(0, i)) && util(A.substr(i, n - 1), root))
            {
                return 1;
            }
        }

        return 0;
    }

    int wordBreak(string A, vector<string> &B)
    {
        // code here
        TrieNode *root = new TrieNode();

        for (auto word : B)
        {
            insert(root, word);
        }

        return util(A, root);
    }
};