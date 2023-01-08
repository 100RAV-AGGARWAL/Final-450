class Solution
{
public:
    int editDistance(string s, string t)
    {
        // Code here
        int slen = s.length(), tlen = t.length();
        int dp[slen + 1][tlen + 1];

        for (int i = 0; i <= slen; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 0; i <= tlen; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= slen; i++)
        {
            for (int j = 1; j <= tlen; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // min(replace, min(delete, insert))
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        return dp[slen][tlen];
    }
};