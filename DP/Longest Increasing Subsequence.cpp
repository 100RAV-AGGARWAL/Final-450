class Solution
{
public:
    int solve(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int take = 0, nottake = 0;

        if (prev == -1 || a[curr] > a[prev])
        {
            take = 1 + solve(n, a, curr + 1, curr, dp);
        }

        nottake = solve(n, a, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, nottake);
    }

    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return solve(n, a, 0, -1, dp);
    }
};