class Solution
{
public:
    int findRightmostSetPos(int a)
    {
        int pos = 0;
        while (a)
        {
            if (a & 1)
                break;

            a = a >> 1;
            pos++;
        }

        return pos;
    }

    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int ans = 0;
        for (auto i : nums)
            ans ^= i;

        int pos = findRightmostSetPos(ans);

        int set = 0, unset = 0;
        for (auto i : nums)
        {
            if (i >> pos & 1)
                set ^= i;
            else
                unset ^= i;
        }

        return {min(set, unset), max(set, unset)};
    }
};