#define ll long long
class Solution
{
public:
    long long countPairs(int n, int arr[], int k)
    {
        // code here
        ll ans = 0;

        map<int, ll> mp;

        for (int i = 0; i < n; i++)
        {
            int num = arr[i] % k;

            if (mp.find(num) != mp.end())
            {
                ans += mp[num];
            }

            mp[num]++;
        }

        return ans;
    }
};