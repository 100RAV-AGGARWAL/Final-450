class Solution
{
public:
    int inSequence(int A, int B, int C)
    {
        // code here
        if ((B < A && C > 0) || (B > A && C < 0))
            return 0;

        if (C == 0)
        {
            if (A == B)
                return 1;
            else
                return 0;
        }

        int t = ((B - A) % C);

        if (t == 0)
            return 1;

        return 0;
    }
};