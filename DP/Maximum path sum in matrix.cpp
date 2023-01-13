class Solution
{
public:
    int dp[501][501];

    int solve(int N, vector<vector<int>> &mat, int r, int c)
    {
        if (r < 0 || c < 0 || c >= N || r >= N)
            return 0;

        if (r == N - 1)
            return mat[r][c];

        if (dp[r][c] != -1)
            return dp[r][c];

        int ans = mat[r][c] + max(solve(N, mat, r + 1, c), max(solve(N, mat, r + 1, c + 1), solve(N, mat, r + 1, c - 1)));

        return dp[r][c] = ans;
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        memset(dp, -1, sizeof(dp));

        int mx = 0;

        for (int i = 0; i < N; i++)
        {
            mx = max(mx, solve(N, Matrix, 0, i));
        }

        return mx;
    }
};