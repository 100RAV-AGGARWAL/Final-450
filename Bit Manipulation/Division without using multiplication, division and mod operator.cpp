class Solution
{
public:
    long long divide(long long dividend, long long divisor)
    {
        // code here
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        dividend = abs(dividend);
        divisor = abs(divisor);

        long long q = 0, rem = 0;

        for (int i = 31; i >= 0; i--)
        {
            if (rem + (divisor << i) <= dividend)
            {
                rem += (divisor << i);
                q |= 1ll << i;
            }
        }

        return q * sign;
    }
};