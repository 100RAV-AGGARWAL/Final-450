class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int result = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mat[i - 1][j - 1])
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                    result = max(result, dp[i][j]);
                }
            }
        }

        return result;
    }
};