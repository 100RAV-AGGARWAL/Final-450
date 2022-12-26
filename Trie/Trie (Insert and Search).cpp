// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

void insert(struct TrieNode *root, string key)
{
    TrieNode *node = root;

    for (int i = 0; i < key.length(); i++)
    {
        if (node->children[key[i] - 'a'] == NULL)
        {
            node->children[key[i] - 'a'] = new TrieNode();
        }

        node = node->children[key[i] - 'a'];
    }

    node->isLeaf = true;
}

bool search(struct TrieNode *root, string key)
{
    TrieNode *node = root;

    for (auto i : key)
    {
        if (node->children[i - 'a'] == NULL)
            return false;

        node = node->children[i - 'a'];
    }

    return node->isLeaf;
}