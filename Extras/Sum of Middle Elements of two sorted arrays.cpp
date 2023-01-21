class Solution
{
public:
    int findMidSum(int ar1[], int ar2[], int n)
    {
        // code here
        int i = 0, j = 0;
        int cnt = 0, c = 0;
        int ans = 0;

        if (n == 1)
            return ar1[0] + ar2[0];

        while (i < n && j < n)
        {
            if (ar1[i] < ar2[j])
                i++;
            else
                j++;

            if (i == n || j == n)
                break;

            cnt++;

            if (cnt > n)
                break;

            if (cnt >= n - 1)
            {
                ans += min(ar1[i], ar2[j]);
                c++;
            }
        }

        if (c == 1)
        {
            if (i == n)
                ans += ar2[j];
            else
                ans += ar1[i];
        }

        return ans;
    }
};