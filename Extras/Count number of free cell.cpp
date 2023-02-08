class Solution
{
public:
    vector<long long int> countZero(int n, int k, vector<vector<int>> &arr)
    {
        // Code Here
        vector<long long int> ans;
        unordered_set<int> r, c;

        for (auto &a : arr)
        {
            r.insert(a[0]);
            c.insert(a[1]);

            ans.push_back((n - r.size()) * (n - c.size()));
        }

        return ans;
    }
};