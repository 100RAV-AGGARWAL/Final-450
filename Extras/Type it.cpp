class Solution
{
public:
    void solve(string s, int &ans, bool &flag)
    {
        int n = s.length();
        if (n == 0)
            return;

        if (!flag && s.substr(0, n / 2) == s.substr(n / 2))
        {
            ans += (n / 2) + 1;
            flag = true;
            return;
        }
        else
        {
            ans++;
            solve(s.substr(0, n - 1), ans, flag);
        }
    }

    int minOperation(string s)
    {
        // code here
        int n = s.length();
        bool flag = false;
        int ans = 0;

        solve(s, ans, flag);

        return ans;
    }
};