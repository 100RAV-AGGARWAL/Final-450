class Solution
{
public:
    int solve(int a, int b)
    {
        // code here
        if (a == b)
            return 0;

        int x = a ^ b;
        int y = a & x;
        int z = b & x;

        if (x == y || x == z)
            return 1;

        return 2;
    }
};