class Solution
{
public:
    int findPosition(int a)
    {
        // code here
        // checked if no is 0 or it contains more than one 1s
        if (a == 0 || (a & (a - 1)))
            return -1;

        // here number is a perfect square of 2
        return log2(a) + 1;
    }
};