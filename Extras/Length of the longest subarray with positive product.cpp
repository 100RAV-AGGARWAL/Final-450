class Solution
{
public:
    // Function to return the length of the
    // longest subarray with ppositive product
    int maxLength(vector<int> &arr, int n)
    {
        // code here
        int ans = 0, neg = 0, pos = 0;
        for (auto i : arr)
        {
            if (i == 0)
            {
                neg = 0;
                pos = 0;
            }
            else if (i > 0)
            {
                pos++;
                if (neg > 0)
                    neg++;
                ans = max(ans, pos);
            }
            else
            {
                swap(pos, neg);
                neg++;
                if (pos > 0)
                    pos++;
                ans = max(ans, pos);
            }
        }

        return ans;
    }
};