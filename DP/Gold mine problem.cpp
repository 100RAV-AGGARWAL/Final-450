class Solution
{
public:
    bool isSafe(int n, int m, int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int solve(int n, int m, vector<vector<int>> M, int i, int j, vector<vector<int>> &dp)
    {
        if (!isSafe(n, m, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (j == m - 1)
        {
            return dp[i][j] = M[i][j];
        }

        int x = M[i][j] + solve(n, m, M, i, j + 1, dp);
        int y = M[i][j] + solve(n, m, M, i - 1, j + 1, dp);
        int z = M[i][j] + solve(n, m, M, i + 1, j + 1, dp);

        return dp[i][j] = max(x, max(y, z));
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int mx = 0;

        for (int i = 0; i < n; i++)
        {
            mx = max(mx, solve(n, m, M, i, 0, dp));
        }

        return mx;
    }
};