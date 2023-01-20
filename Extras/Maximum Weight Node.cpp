class Solution
{
public:
    int maxWeightCell(int N, vector<int> Edge)
    {
        // code here
        vector<int> wt(N, 0);

        for (int i = 0; i < N; i++)
        {
            if (Edge[i] != -1)
                wt[Edge[i]] += i;
        }

        int ans = 0, ind = -1;
        for (int i = 0; i < N; i++)
        {
            if (wt[i] >= ans)
            {
                ans = wt[i];
                ind = i;
            }
        }

        return ind;
    }
};