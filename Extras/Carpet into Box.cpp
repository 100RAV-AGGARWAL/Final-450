class Solution
{
public:
    int moves(int x, int X)
    {
        int ans = 0;

        while (x > X)
        {
            ans++;
            x /= 2;
        }

        return ans;
    }

    int carpetBox(int A, int B, int C, int D)
    {
        // code here
        return min(moves(A, C) + moves(B, D), moves(A, D) + moves(B, C));
    }
};