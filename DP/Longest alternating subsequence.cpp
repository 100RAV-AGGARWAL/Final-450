class Solution
{
public:
    int AlternatingaMaxLength(vector<int> &nums)
    {
        // Code here
        int n = nums.size();
        int up = 1, down = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }

        return max(up, down);
    }
};