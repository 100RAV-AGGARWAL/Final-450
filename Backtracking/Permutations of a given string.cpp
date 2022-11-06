class Solution
{
public:
    void util(string S, set<string> &ans, int ind)
    {
        if (S.length() == ind)
        {
            ans.insert(S);
            return;
        }

        for (int i = ind; i < S.length(); i++)
        {
            swap(S[i], S[ind]);
            util(S, ans, ind + 1);
            swap(S[i], S[ind]);
        }
    }

    vector<string> find_permutation(string S)
    {
        // Code here there
        vector<string> result;
        set<string> ans;

        util(S, ans, 0);

        result.assign(ans.begin(), ans.end());
        sort(result.begin(), result.end());
        
        return result;
    }
};
