class Solution
{
public:
    int maxInstance(string s)
    {
        unordered_map<char, int> m;
        for (auto str : s)
        {
            m[str]++;
        }
        int mini = INT_MAX;
        mini = min({m['b'], m['a'], m['l'] / 2, m['o'] / 2, m['n']});
        return mini;
    }
};