class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int solve(int n, int k, vector<vector<int>> &dp)
    {
        if (k == 0 || k == 1 || n == 1)
            return k;

        if (dp[n][k] != -1)
            return dp[n][k];

        int mn = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            int a1 = dp[n - 1][i - 1] != -1 ? dp[n - 1][i - 1] : solve(n - 1, i - 1, dp);
            int a2 = dp[n][k - i] != -1 ? dp[n][k - i] : solve(n, k - i, dp);
            int temp = 1 + max(a1, a2);

            mn = min(mn, temp);
        }

        return dp[n][k] = mn;
    }

    int eggDrop(int n, int k)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return solve(n, k, dp);
    }
};