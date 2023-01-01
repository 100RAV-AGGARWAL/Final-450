class Solution
{
public:
    int mod = 1000000007;
    int inv(int n, int m)
    {
        if (m == 0)
            return 1;

        if (m & 1)
            return (n * 1ll * inv(n, m - 1)) % mod;

        int tmp = inv(n, m / 2);

        return (tmp * 1ll * tmp) % mod;
    }
    int compute_value(int n)
    {
        // Code here
        long long f2 = 1, f;

        for (int i = 1; i <= 2 * n; i++)
        {
            f2 *= i;
            f2 %= mod;

            if (i == n)
                f = f2;
        }

        f = (f * f) % mod;
        return (f2 * 1ll * inv(f, mod - 2)) % mod;
    }
};