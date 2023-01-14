class Solution
{
public:
    int removals(vector<int> &arr, int k)
    {
        // Code here
        int ans = INT_MAX;
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int idx = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin() - 1;
            ans = min(ans, i + n - idx - 1);
        }

        return ans;
    }
};