class Solution
{
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        // SIMILAR TO KNAPSACK
        int cut[3] = {x, y, z};
        int dp[4][n + 1];

        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                    dp[i][j] = INT_MIN;
                if (j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cut[i - 1] <= j)
                {
                    dp[i][j] = max(dp[i][j - cut[i - 1]] + 1, dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[3][n] < 0)
            return 0;
        else
            return dp[3][n];
    }
};