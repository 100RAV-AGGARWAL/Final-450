#define ll long long int
class Solution
{
public:
    long long solve(long long l, long long r)
    {
        return f(r, 63, 0, 0) - f(l - 1, 63, 0, 0);
    }

    ll f(ll n, ll idx, int count_set_bit, int set)
    {
        if (count_set_bit == 3)
        {
            return 1;
        }
        if (idx < 0)
            return 0;

        ll ans = 0;
        if (isSet(n, idx))
        {
            ans += f(n, idx - 1, count_set_bit + 1, set & 1);
            ans += f(n, idx - 1, count_set_bit, 1);
        }
        else
        {
            if (set == 1)
            {
                ans += f(n, idx - 1, count_set_bit + 1, set);
                ans += f(n, idx - 1, count_set_bit, set);
            }
            else
            {
                ans += f(n, idx - 1, count_set_bit, set);
            }
        }

        return ans;
    }

    bool isSet(ll n, ll idx)
    {
        ll one = 1;
        ll mask = (one << idx);
        return (n & mask) != 0;
    }
};
