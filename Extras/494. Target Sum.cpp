class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (auto it : nums)
        {
            sum += it;
        }

        int n = nums.size();

        if (sum < target || target < (-sum))
            return 0;

        int x = (sum + target) / 2;

        if (x + x - target < sum)
            return 0;

        int dp[n + 1][x + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= x; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= x; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][x];
    }
};