vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> ans;
    queue<int> q;
    int j = 0;

    for (int i = 0; i < N;)
    {
        if (A[i] < 0)
            q.push(A[i]);

        if (i - j + 1 < K)
            i++;
        else if (i - j + 1 == K)
        {
            if (q.empty())
                ans.push_back(0);
            else
                ans.push_back(q.front());

            if (A[j] == q.front())
                q.pop();
            i++;
            j++;
        }
    }

    return ans;
}