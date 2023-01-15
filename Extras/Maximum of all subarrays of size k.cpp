class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < k - 1; i++)
        {
            pq.push({arr[i], i});
        }

        int i = 0, j = k - 1;

        while (j < n)
        {
            while (!pq.empty() && i > pq.top().second)
            {
                pq.pop();
            }

            pq.push({arr[j], j});

            ans.push_back(pq.top().first);

            i++;
            j++;
        }

        return ans;
    }
};