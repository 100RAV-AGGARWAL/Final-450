class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        if (n < 4)
            return ans;

        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {

                int start = j + 1, end = n - 1;
                while (start < end)
                {
                    int sum = arr[i] + arr[j] + arr[start] + arr[end];
                    if (sum == k)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[start], arr[end]};
                        if (find(ans.begin(), ans.end(), temp) == ans.end())
                            ans.push_back(temp);

                        while (start < end && arr[start] == temp[2])
                            start++;
                        while (start < end && arr[end] == temp[3])
                            end--;
                    }
                    else if (sum < k)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }
                while (j < n - 3 && arr[j + 1] == arr[j])
                    j++;
            }
            while (i < n - 4 && arr[i + 1] == arr[i])
                i++;
        }
        return ans;
    }
};