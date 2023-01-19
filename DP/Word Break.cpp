class Solution
{
public:
    set<string> dict;
    map<int, bool> mp;

    int solve(string A, int idx, int n)
    {
        if (idx == n)
            return true;

        if (mp.find(idx) != mp.end())
        {
            return mp[idx];
        }

        for (int i = idx; i < n; i++)
        {
            if (dict.find(A.substr(idx, i - idx + 1)) != dict.end() && solve(A, i + 1, n))
            {
                return mp[idx] = true;
            }
        }

        return mp[idx] = false;
    }

    int wordBreak(string A, vector<string> &B)
    {
        // code here

        for (auto s : B)
        {
            dict.insert(s);
        }

        int n = A.length();

        return solve(A, 0, n);
    }
};