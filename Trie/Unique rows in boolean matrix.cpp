#define SIZE 2

struct TrieNode
{
    bool isLeaf;
    TrieNode *children[SIZE];

    TrieNode()
    {
        isLeaf = false;

        for (int i = 0; i < SIZE; i++)
        {
            children[i] = NULL;
        }
    }
};

void insert(TrieNode *root, int M[MAX][MAX], int col, int r)
{
    TrieNode *node = root;
}

/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    // Your code here
    TrieNode *root = new TrieNode();
    vector<vector<int>> ans;

    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        TrieNode *node = root;

        for (int j = 0; j < col; j++)
        {
            int ind = M[i][j];
            temp.push_back(ind);

            if (node->children[ind] == NULL)
            {
                node->children[ind] = new TrieNode();
            }

            node = node->children[ind];
        }

        if (!node->isLeaf)
        {
            node->isLeaf = true;
            ans.push_back(temp);
        }
    }

    return ans;
}