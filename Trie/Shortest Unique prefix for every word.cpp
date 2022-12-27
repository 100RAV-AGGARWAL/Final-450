struct TrieNode {
    bool isLeaf;
    TrieNode* children[26];
    int count;
    
    TrieNode() {
        isLeaf = false;
        count = 0;
        
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution
{
    public:
    void insert(TrieNode *root, string key)
    {
        TrieNode *node = root;
    
        for (int i = 0; i < key.length(); i++)
        {
            if (node->children[key[i] - 'a'] == NULL)
            {
                node->children[key[i] - 'a'] = new TrieNode();
            }
            
            node->count++;
            node = node->children[key[i] - 'a'];
        }
            
        node->count++;
        node->isLeaf = true;
    }
    
    string search(TrieNode *root, string key)
    {
        TrieNode *node = root;
        string pre="";
    
        for (auto i : key)
        {
            if (node->children[i - 'a']->count == 1) {
                pre += i;
                break;
            }
            
            pre += i;
            node = node->children[i - 'a'];
        }
    
        return pre;
    }
    
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        TrieNode *root = new TrieNode();
        vector<string> ans;
        
        for(int i=0; i<n; i++) {
            insert(root, arr[i]);
        }
        
        for(int i=0; i<n; i++) {
            ans.push_back(search(root, arr[i]));
        }
        
        return ans;
    }
    
};