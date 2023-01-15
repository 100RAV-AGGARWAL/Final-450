class Solution
{
public:
    long long countSubstring(string S)
    {
        // code here
        int n = S.length(), sum = 0, onesekam = 0;
        long long ans = 0;
        map<int, int> mp;

        for (auto ch : S)
        {
            if (ch == '1')
                sum++;
            else
                sum--;

            mp[sum]++;
            if (sum <= 0)
                onesekam++;
        }

        sum = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (n - i - onesekam);

            if (S[i] == '0')
            {
                sum--;
                mp[sum]--;
                onesekam--;
                onesekam -= mp[sum + 1];
            }
            else
            {
                sum++;
                mp[sum]--;
                onesekam += mp[sum];
            }
        }

        return ans;
    }