class Solution
{
public:
    int maxProfit(int K, int N, int A[])
    {
        // code here
        // vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(2, vector<int>(K+1, 0)));
        vector<vector<int>> after(2, vector<int>(K + 1, 0));
        vector<vector<int>> curr(2, vector<int>(K + 1, 0));

        //buy = if we can buy current stock or not (cannot buy if previous stock bought but not sold)
        //cap = no fo transactions done
        for (int ind = N - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= K; cap++)
                {

                    if (buy)
                    {
                        curr[buy][cap] = max(-A[ind] + after[0][cap], after[1][cap]);
                    }
                    else
                    {
                        curr[buy][cap] = max(A[ind] + after[1][cap - 1], after[0][cap]);
                    }
                }
            }
            after = curr;
        }

        return after[1][K];
    }
};