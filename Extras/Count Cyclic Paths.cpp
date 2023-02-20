class Solution
{
public:
    const int mod = 1e9 + 7;
    int countPaths(int n)
    {
        long long int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = ((ans % mod) * 3) % mod;
            if (i % 2 == 1)
                ans = (ans + 3) % mod;
            else
                ans = ans - 3;
        }
        return ans % mod;
    }
};