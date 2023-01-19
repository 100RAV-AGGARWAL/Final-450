class Solution
{
public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C)
    {
        // Your code here
        int N = A.size();
        int M = B.size();

        bool dp[N + 1][M + 1];
        memset(&dp, false, sizeof(dp));

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= M; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (A[i - 1] == C[i + j - 1])
                {
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                }

                if (B[j - 1] == C[i + j - 1])
                {
                    dp[i][j] = dp[i][j] | dp[i][j - 1];
                }
            }
        }

        return dp[N][M];
    }
};