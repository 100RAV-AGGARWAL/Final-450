class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0, mx = 0;

        for (int i = 0; i < n; i++)
        {
            mx = sum += arr[i];
        }

        bool dp[n + 1][mx + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= mx; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int i = 0; i <= sum / 2; i++)
        {
            if (dp[n][i])
                mx = min(mx, sum - 2 * i);
        }

        return mx;
    }
};