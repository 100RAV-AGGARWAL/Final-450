//Minimum no of coins

class Solution
{
public:
    int coinChange(vector<int> &coins, int sum)
    {
        int N = coins.size();
        int dp[N + 1][sum + 1];

        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= sum; i++)
        {
            dp[0][i] = INT_MAX - 1;
        }

        for (int i = 1; i <= sum; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[1][i] = i / coins[0];
            }
            else
            {
                dp[1][i] = INT_MAX - 1;
            }
        }

        for (int i = 2; i <= N; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][sum] == INT_MAX - 1 ? -1 : dp[N][sum];
    }
};