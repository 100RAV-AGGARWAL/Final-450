struct TrieNode
{
    bool isLeaf;
    TrieNode *children[26];
    vector<int> v;

    TrieNode()
    {
        isLeaf = false;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};
class Solution{
  public:
    void insert(TrieNode *root, string key, int pos)
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
        
        node->v.push_back(pos);
        node->isLeaf = true;
    }
    
    void solve(TrieNode *root, vector<string>& words, vector<vector<string>>& ans) {
        if(root->isLeaf) {
            vector<string> t;
            for(auto i : root->v) {
                t.push_back(words[i]);
            }
            ans.push_back(t);
        } 
        
        for(int i=0; i<26; i++) {
            if(root->children[i]) {
                solve(root->children[i], words, ans);
            }
        }
    }

    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        TrieNode *root = new TrieNode();
        
        for(int i=0; i<string_list.size(); i++) {
            string temp = string_list[i];
            sort(temp.begin(), temp.end());
            
            insert(root, temp, i);
        }
        
        solve(root, string_list, ans);
        
        return ans;
    }
};