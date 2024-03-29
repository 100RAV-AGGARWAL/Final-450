class Solution
{
public:
    int findWinner(int N, int X, int Y)
    {
        // Your code goes here
        bool dp[N + 1];

        dp[0] = false;
        dp[1] = true;

        for (int i = 2; i <= N; i++)
        {
            if (i - 1 >= 0 && !dp[i - 1])
                dp[i] = true;
            else if (i - X >= 0 && !dp[i - X])
                dp[i] = true;
            else if (i - Y >= 0 && !dp[i - Y])
                dp[i] = true;
            else
                dp[i] = false;
        }

        return dp[N];
    }
};