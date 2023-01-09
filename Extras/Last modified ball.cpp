class Solution
{
public:
    int solve(int N, vector<int> A)
    {
        // code here
        int ans = N;
        int c = 1;
        for (int i = N - 1; i >= 0; i--)
        {
            int sum = A[i] + c;

            if (sum <= 9)
            {
                return ans;
            }
            else
            {
                ans--;
            }
        }

        return ans;
    }
};