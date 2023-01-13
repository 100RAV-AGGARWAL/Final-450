class Solution
{
public:
    int solve(int arr[], int N, int K, int curr, int prev, vector<vector<int>> &dp)
    {
        if (prev < 0)
            return 0;

        if (dp[curr][prev] != -1)
            return dp[curr][prev];

        int take = 0, nottake = 0;

        if (arr[curr] - arr[prev] < K)
        {
            take = arr[curr] + arr[prev] + solve(arr, N, K, prev - 1, prev - 2, dp);
        }

        nottake = solve(arr, N, K, curr - 1, prev - 1, dp);

        return dp[curr][prev] = max(take, nottake);
    }

    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

        sort(arr, arr + N);

        return solve(arr, N, K, N - 1, N - 2, dp);
    }
};