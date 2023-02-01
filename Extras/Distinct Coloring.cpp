class Solution
{
public:
    long long int solve(int r[], int g[], int b[], int N, int i, int flag, vector<vector<long long int>> &dp)
    {
        if (i == N)
            return 0;

        if (dp[i][flag] != -1)
            return dp[i][flag];

        long long int taker = 1e11, takeg = 1e11, takeb = 1e11;

        if (flag == 0)
        {
            taker = r[i] + solve(r, g, b, N, i + 1, 1, dp);
            takeg = g[i] + solve(r, g, b, N, i + 1, 2, dp);
            takeb = b[i] + solve(r, g, b, N, i + 1, 3, dp);
        }
        else if (flag == 1)
        {
            takeg = g[i] + solve(r, g, b, N, i + 1, 2, dp);
            takeb = b[i] + solve(r, g, b, N, i + 1, 3, dp);
        }
        else if (flag == 2)
        {
            taker = r[i] + solve(r, g, b, N, i + 1, 1, dp);
            takeb = b[i] + solve(r, g, b, N, i + 1, 3, dp);
        }
        else
        {
            taker = r[i] + solve(r, g, b, N, i + 1, 1, dp);
            takeg = g[i] + solve(r, g, b, N, i + 1, 2, dp);
        }

        return dp[i][flag] = min(taker, min(takeg, takeb));
    }

    long long int distinctColoring(int N, int r[], int g[], int b[])
    {
        // code here
        vector<vector<long long int>> dp(N, vector<long long int>(4, -1));

        return solve(r, g, b, N, 0, 0, dp);
    }
};