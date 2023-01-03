class Solution
{
public:
    long long mod = 1e3 + 3;
    int solve(string str, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
            return 0;

        if (i == j)
        {
            if (isTrue)
                return str[i] == 'T';
            else
                return str[i] == 'F';
        }

        int isT = (isTrue == true) ? 0 : 1;

        if (dp[i][j][isT] != -1)
            return dp[i][j][isT];

        int ans = 0;

        for (int k = i + 1; k < j; k += 2)
        {
            int lT, lF, rT, rF;

            lT = (dp[i][k - 1][0] != -1) ? dp[i][k - 1][0] : solve(str, i, k - 1, true, dp);

            lF = (dp[i][k - 1][1] != -1) ? dp[i][k - 1][1] : solve(str, i, k - 1, false, dp);

            rT = (dp[k + 1][j][0] != -1) ? dp[k + 1][j][0] : solve(str, k + 1, j, true, dp);

            rF = (dp[k + 1][j][1] != -1) ? dp[k + 1][j][1] : solve(str, k + 1, j, false, dp);

            if (str[k] == '|')
            {
                if (isTrue)
                {
                    ans += ((lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                }
                else
                {
                    ans += (lF * rF) % mod;
                }
            }
            else if (str[k] == '&')
            {
                if (isTrue)
                {
                    ans += (lT * rT) % mod;
                }
                else
                {
                    ans += ((lF * rF) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                }
            }
            else if (str[k] == '^')
            {
                if (!isTrue)
                {
                    ans += ((lT * rT) % mod + (lF * rF) % mod) % mod;
                }
                else
                {
                    ans += ((lT * rF) % mod + (lF * rT) % mod) % mod;
                }
            }
        }

        dp[i][j][isT] = ans;
        return ans % mod;
    }

    int countWays(int n, string str)
    {
        // code here
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return solve(str, 0, n - 1, true, dp);
    }
};