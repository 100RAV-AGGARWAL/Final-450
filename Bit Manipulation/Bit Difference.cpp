class Solution
{
public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {

        // Your logic here
        int ans = a ^ b;

        int res = 0;
        while (ans)
        {
            ans = ans & (ans - 1);
            res++;
        }

        return res;
    }
};