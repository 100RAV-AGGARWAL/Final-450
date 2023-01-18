class Solution
{
public:
    int solve(vector<int> &nums, int n, int k, int i, int spFilled, vector<vector<int>> &dp)
    {
        if (i == n)
            return 0;

        if (dp[i][spFilled] != -1)
            return dp[i][spFilled];

        if (spFilled != 0)
        {
            int take = 1e9, nottake = 1e9;

            if (spFilled + nums[i] + 1 <= k)
            {
                take = solve(nums, n, k, i + 1, spFilled + nums[i] + 1, dp);
            }

            int spLeft = k - spFilled;
            nottake = spLeft * spLeft + solve(nums, n, k, i, 0, dp);

            return dp[i][spFilled] = min(take, nottake);
        }
        else
        {
            return dp[i][spFilled] = solve(nums, n, k, i + 1, nums[i], dp);
        }
    }

    int solveWordWrap(vector<int> nums, int k)
    {
        // Code here
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return solve(nums, n, k, 0, 0, dp);
    }
};