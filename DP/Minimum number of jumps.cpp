class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        int jumps = 0, curMax = 0, curReach = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (i + arr[i] > curMax)
                curMax = arr[i] + i;

            if (i == curReach)
            {
                jumps++;
                curReach = curMax;
            }

            if (arr[i] == 0 && i == curMax)
                return -1;
        }

        return jumps;
    }
};