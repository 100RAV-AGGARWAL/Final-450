/*
The structure to use is as follows
struct val{
    int first;
    int second;
};*/

class Solution
{
public:
    static bool comp(struct val a, struct val b)
    {
        return a.second < b.second;
    }
    // int solve(struct val p[], int n, int curr, int prev, vector<vector<int>> &dp) {
    //     if(curr == n) return 0;

    //     if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

    //     int take=0, nottake=0;

    //     if(prev == -1 || p[curr].first > p[prev].second) {
    //         take = 1 + solve(p, n, curr+1, curr, dp);
    //     }

    //     nottake = solve(p, n, curr+1, prev, dp);

    //     return dp[curr][prev+1] = max(take, nottake);
    // }

    // int maxChainLen(struct val p[],int n){
    //     //Your code here
    //     vector<vector<int>> dp(n, vector<int>(n+1, -1));

    //     sort(p, p+n, comp);

    //     return solve(p, n, 0, -1, dp);
    // }

    //GREEDY APPROACH
    int maxChainLen(struct val p[], int n)
    {
        sort(p, p + n, comp);

        int ans = 1, prev = p[0].second;

        for (int i = 1; i < n; ++i)
        {
            if (p[i].first > prev)
            {
                ans++;
                prev = p[i].second;
            }
        }

        return ans;
    }
};