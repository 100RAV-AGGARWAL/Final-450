class Solution
{
public:
    int smallestSumSubarray(vector<int> &a)
    {
        // Code here
        int sum = 0, mn = INT_MAX;

        for (auto i : a)
        {
            if (sum > 0)
                sum = i;
            else
                sum += i;

            mn = min(mn, sum);
        }

        return mn;
    }
};