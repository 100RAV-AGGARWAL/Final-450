class Solution
{
public:
    int minimizeSum(int N, vector<int> arr)
    {
        // code here
        int sum = 0;

        if (N == 1)
            return 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < N; i++)
        {
            pq.push(arr[i]);
        }

        while (pq.size() != 1)
        {
            int n1 = pq.top();
            pq.pop();
            int n2 = pq.top();
            pq.pop();

            sum += n1 + n2;

            pq.push(n1 + n2);
        }

        return sum;
    }
};