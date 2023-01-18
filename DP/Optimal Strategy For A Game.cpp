class Solution
{
public:
    long long solve(int arr[], int i, int j, vector<vector<long long>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        auto first = arr[i] + min(solve(arr, i + 1, j - 1, dp), solve(arr, i + 2, j, dp));
        auto last = arr[j] + min(solve(arr, i, j - 2, dp), solve(arr, i + 1, j - 1, dp));

        return dp[i][j] = max(first, last);
    }

    long long maximumAmount(int arr[], int n)
    {
        // Your code here
        vector<vector<long long>> dp(n, vector<long long>(n, -1));

        return solve(arr, 0, n - 1, dp);
    }
};