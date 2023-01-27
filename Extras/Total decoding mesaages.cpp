#define ll long long
#define mod (int)(1e9 + 7)
class Solution
{
public:
    int solve(string &str, int n, int idx, vector<ll> &dp)
    {
        if (idx == n)
            return 1;

        if (dp[idx] != -1)
            return dp[idx];

        int one = 0, two = 0;
        if (str[idx] >= '1' && str[idx] <= '9')
        {
            one = solve(str, n, idx + 1, dp);
        }

        string ch = str.substr(idx, 2);
        if (idx < n - 1 && ch >= "10" && ch <= "26")
        {

            two = solve(str, n, idx + 2, dp);
        }

        return dp[idx] = (one + two) % mod;
    }
    int CountWays(string str)
    {
        // Code here
        int n = str.length();
        vector<ll> dp(n, -1);
        return solve(str, n, 0, dp);
    }
};