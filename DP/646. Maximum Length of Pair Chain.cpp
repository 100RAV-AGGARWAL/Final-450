class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int solve(vector<vector<int>> &pairs, int prev, int curr, int n, vector<vector<int>> &dp)
    {
        if (curr == n)
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int take = 0, nottake = 0;

        if (prev == -1 || pairs[curr][0] > pairs[prev][1])
        {
            take = 1 + solve(pairs, curr, curr + 1, n, dp);
        }

        nottake = solve(pairs, prev, curr + 1, n, dp);

        return dp[curr][prev + 1] = max(take, nottake);
    }

    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(pairs, -1, 0, n, dp);
    }
};