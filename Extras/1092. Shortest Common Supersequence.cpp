class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int x = s1.length(), y = s2.length();
        int dp[x + 1][y + 1];

        for (int i = 0; i <= x; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= y; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = x;
        int j = y;
        string ans = "";

        while (i >= 1 && j >= 1)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans += s1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s1[i - 1];
                i--;
            }
            else
            {
                ans += s2[j - 1];
                j--;
            }
        }

        while(i>0) {
            ans += s1[i - 1];
            i--;
        }

        while(j>0) {
            ans += s2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};