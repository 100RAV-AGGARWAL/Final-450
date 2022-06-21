class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        vector<int> left(n), right(n);

        int max_l = arr[0];
        for (int i = 0; i < n; i++)
        {
            max_l = max(max_l, arr[i]);
            left[i] = max_l;
        }

        int max_r = arr[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            max_r = max(max_r, arr[i]);
            right[i] = max_r;
        }

        long long trapped = 0;
        for (int i = 0; i < n; i++)
        {
            int m = min(left[i], right[i]);
            trapped += max(m - arr[i], 0);
        }

        return trapped;
    }
};