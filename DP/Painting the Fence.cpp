class Solution
{
public:
    int mod = 1000000007;

    long long solve(int n, int k, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;

        if (dp[n] != -1)
            return dp[n];

        long long same = ((k - 1) * solve(n - 2, k, dp)) % mod;
        long long diff = ((k - 1) * solve(n - 1, k, dp)) % mod;

        return dp[n] = (same + diff) % mod;
    }

    long long countWays(int n, int k)
    {
        // code here
        vector<int> dp(n + 1, -1);

        return solve(n, k, dp);
    }
};