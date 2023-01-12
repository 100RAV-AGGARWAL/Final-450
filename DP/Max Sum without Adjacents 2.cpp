class Solution
{
public:
    // int solve(vector<int> arr, int n, int curr, int prev1, int prev2, vector<vector<vector<int>>> &dp)
    // {
    //     if (curr == n)
    //         return 0;

    //     if (dp[curr][prev1 + 1][prev2 + 2] != -1)
    //         return dp[curr][prev1 + 1][prev2 + 2];

    //     int take = 0, nottake = 0;

    //     if (prev1 == -1 || prev2 < 0 || !(curr == prev1 + 1 && prev1 == prev2 + 1 ))
    //     {
    //         take = arr[curr] + solve(arr, n, curr + 1, curr, prev1, dp);
    //     }

    //     nottake = solve(arr, n, curr + 1, prev1, prev2, dp);

    //     return dp[curr][prev1 + 1][prev2 + 2] = max(take, nottake);
    // }

    int findMaxSum(vector<int> &a)
    {

        int n = a.size();

        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(n+2, -1)));
        // return solve(arr, n, 0, -1, -2, dp);

        vector<int> dp(n);
        dp[0] = a[0];
        dp[1] = a[0] + a[1];
        dp[2] = max({a[0] + a[1], a[1] + a[2], a[0] + a[2]});

        for (int i = 3; i < n; i++)
        {
            int excluded = dp[i - 1];
            int two = a[i] + a[i - 1] + dp[i - 3];
            int one = a[i] + dp[i - 2];

            dp[i] = max({excluded, one, two});
        }

        return dp[n - 1];
    }
};