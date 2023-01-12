class Solution
{
public:
    int solve(int arr[], int n, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int take = 0, nottake = 0;

        if (prev == -1 || arr[curr] > arr[prev])
        {
            take = arr[curr] + solve(arr, n, curr + 1, curr, dp);
        }

        nottake = solve(arr, n, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, nottake);
    }

    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(arr, n, 0, -1, dp);
    }
};