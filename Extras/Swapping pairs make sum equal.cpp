class Solution
{

public:
    int calcSum(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    int findSwapValues(int A[], int n, int B[], int m)
    {
        int sumA = calcSum(A, n);
        int sumB = calcSum(B, m);

        sort(A, A + n);
        sort(B, B + m);

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            int a = sumA - A[i] + B[j];
            int b = sumB - B[j] + A[i];

            if (a == b)
                return 1;

            if (a > b)
                i++;
            else
                j++;
        }

        return -1;
    }
};