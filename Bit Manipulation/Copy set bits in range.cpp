class Solution
{
public:
    int setSetBit(int x, int y, int l, int r)
    {
        // code here
        for (int i = l; i <= r; i++)
        {
            if ((1 << (i - 1)) & y)
            {
                x |= (1 << (i - 1));
            }
        }

        return x;
    }
};