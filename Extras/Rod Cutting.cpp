class Solution
{
public:
    int cutRod(int price[], int n)
    {
        // code here
        int dp[n + 1][n + 1];

        int len[n];

        for (int i = 0; i < n; i++)
        {
            len[i] = i + 1;
        }

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (len[i - 1] <= j)
                {
                    dp[i][j] = max(price[i - 1] + dp[i][j - len[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][n];
    }
};