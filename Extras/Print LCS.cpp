#include <bits/stdc++.h>
using namespace std;

// Function to find the length of longest common subsequence in two strings.
void lcs(int x, int y, string s1, string s2)
{
    // your code here
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
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    lcs(s1.length(), s2.length(), s1, s2);
}
