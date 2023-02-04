class Solution
{
public:
    int solve(int *arr, int n, int i, vector<int> &dp)
    {
        if (i >= n)
        {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        int take = arr[i] + solve(arr, n, i + 2, dp);
        int nottake = solve(arr, n, i + 1, dp);

        return dp[i] = max(take, nottake);
    }

    int findMaxSum(int *arr, int n)
    {
        vector<int> dp(n, -1);

        return solve(arr, n, 0, dp);
    }
};