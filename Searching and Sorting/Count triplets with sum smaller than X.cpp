class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        // Your code goes here
        int count = 0;
        sort(arr, arr + n);

        for (int i = 0; i < n - 2; i++)
        {
            int start = i + 1, end = n - 1;
            while (start < end)
            {
                long long s = arr[i] + arr[start] + arr[end];
                if (s < sum)
                {
                    count += (end - start);
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        return count;
    }
};