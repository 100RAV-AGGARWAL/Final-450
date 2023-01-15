class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &arr, int N)
    {
        // code here
        long sum = 0, mx = 0;

        int i = 0, j = 0;

        sum += arr[i];

        while (j < N)
        {
            if (j - i + 1 == K)
            {
                mx = max(mx, sum);
                sum -= arr[i++];
            }

            j++;
            sum += arr[j];
        }

        return mx;
    }
};