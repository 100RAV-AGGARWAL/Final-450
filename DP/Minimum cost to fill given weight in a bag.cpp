class Solution
{

public:
    int minimumCost(int cost[], int N, int W)
    {
        // Your code goes here
        int dp[N + 1][W + 1];

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i == 0)
                    dp[i][j] = 1e9;
                if (j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (i <= j && cost[i - 1] != -1)
                {
                    dp[i][j] = min(cost[i - 1] + dp[i][j - i], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][W] != 1e9 ? dp[N][W] : -1;
    }
};