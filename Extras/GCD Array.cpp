class Solution
{
public:
    int solve(int N, int K, vector<int> &arr)
    {
        // code here
        vector<int> preSum(N);
        preSum[0] = arr[0];
        for (int i = 1; i < N; i++)
        {
            preSum[i] = arr[i] + preSum[i - 1];
        }

        vector<int> factors;
        int sum = preSum[N - 1];

        for (int i = 1; i <= sqrt(sum); i++)
        {
            if (sum % i == 0)
            {
                factors.push_back(i);

                if (i != sum / i)
                    factors.push_back(sum / i);
            }
        }

        int ans = INT_MIN;
        for (auto i : factors)
        {
            int c = 0;

            for (int j = 0; j < N; j++)
            {
                if (preSum[j] % i == 0)
                    c++;
            }

            if (c >= K)
            {
                ans = max(ans, i);
                c = 0;
            }
        }

        return ans;
    }
};