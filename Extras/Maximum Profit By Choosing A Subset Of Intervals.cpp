class Solution
{
public:
    int solve(int idx, vector<vector<int>> &intervals, int n, vector<int> &dp, vector<int> &start)
    {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int ind = lower_bound(start.begin(), start.end(), intervals[idx][1]) - start.begin();

        int take = intervals[idx][2] + solve(ind, intervals, n, dp, start);
        int nottake = solve(idx + 1, intervals, n, dp, start);

        return dp[idx] = max(take, nottake);
    }
    int maximum_profit(int n, vector<vector<int>> &intervals)
    {
        // Write your code here.
        sort(intervals.begin(), intervals.end());
        vector<int> start, dp(n + 1, -1);

        for (auto it : intervals)
        {
            start.push_back(it[0]);
        }

        return solve(0, intervals, n, dp, start);
    }
};