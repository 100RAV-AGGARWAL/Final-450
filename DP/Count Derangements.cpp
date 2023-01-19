class Solution
{
public:
    long int disarrange(int N)
    {
        // code here
        int mod = 1000000007;
        long long int dp[N + 1];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= N; i++)
        {
            dp[i] = ((i - 1) * ((dp[i - 1] + dp[i - 2]) % mod)) % mod;
        }

        return dp[N];
    }
};