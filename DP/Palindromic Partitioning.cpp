class Solution
{
public:
    bool isPalindrome(string str, int i, int j)
    {
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }

    int solve(string str, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;

        if (isPalindrome(str, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int sa1, sa2;

            sa1 = (dp[i][k] != -1) ? dp[i][k] : solve(str, i, k, dp);

            sa2 = (dp[k + 1][j] != -1) ? dp[k + 1][j] : solve(str, k + 1, j, dp);

            int temp = 1 + sa1 + sa2;

            mn = min(mn, temp);
        }

        return dp[i][j] = mn;
    }

    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(str, 0, n - 1, dp);
    }
};