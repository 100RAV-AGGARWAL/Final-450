class Solution
{
public:
    long long int countBT(int h)
    {
        // code here
        long long int dp[h + 1];

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 3;

        int mod = 1000000007;

        for (int i = 3; i <= h; i++)
        {
            dp[i] = (dp[i - 1] * (2 * dp[i - 2] + dp[i - 1])) % mod;
        }

        return dp[h];
    }
};