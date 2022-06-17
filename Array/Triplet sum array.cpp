class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int x)
    {
        sort(A, A + n);
        for (int i = 0; i < n; i++)
        {
            int start = i + 1;
            int end = n - 1;
            while (start < end)
            {
                int sum = A[i] + A[start] + A[end];
                if (sum == x)
                    return true;
                else if (sum > x)
                    end--;
                else
                    start++;
            }
        }
        return false;
    }
};