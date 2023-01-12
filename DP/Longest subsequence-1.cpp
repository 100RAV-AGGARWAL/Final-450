class Solution
{
public:
    int solve(int N, int A[], int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == N)
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int take = 0, nottake = 0;

        if (prev == -1 || abs(A[curr] - A[prev]) == 1)
        {
            take = 1 + solve(N, A, curr + 1, curr, dp);
        }

        nottake = solve(N, A, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, nottake);
    }

    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N + 1, -1));

        return solve(N, A, 0, -1, dp);
    }
};