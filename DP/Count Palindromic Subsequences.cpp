class Solution
{
public:
    long long int solve(string &str, int i, int j, vector<vector<long long int>> &dp)
    {
        if (i == j)
            return 1;
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mod = 1000000007;

        if (str[i] == str[j])
        {
            return dp[i][j] = (1 + solve(str, i + 1, j, dp) + solve(str, i, j - 1, dp)) % mod;
        }
        else
        {
            return dp[i][j] = ((solve(str, i + 1, j, dp) + solve(str, i, j - 1, dp) - solve(str, i + 1, j - 1, dp)) % mod + mod) % mod;
        }
    }

    /*You are required to complete below method */
    long long int countPS(string str)
    {
        // Your code here
        int n = str.length();

        vector<vector<long long int>> dp(n, vector<long long int>(n, -1));

        return solve(str, 0, n - 1, dp);
    }
};