class Solution
{
public:
    int mod = 1000000007;
    int nCr(int n, int r)
    {
        // code here
        if (r > n)
            return 0;
        if (r == n)
            return 1;

        int dp[n + 1][r + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= r; j++)
            {
                if (i == 0 || j == 0 || i == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                }
            }
        }

        return dp[n][r];
    }
};