class Solution
{
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first < b.first;
        }
    }

    int minLaptops(int N, int start[], int end[])
    {
        // Code here
        vector<pair<int, int>> v;
        int ans = 0;

        for (int i = 0; i < N; i++)
        {
            v.push_back({start[i], end[i]});
        }

        sort(v.begin(), v.end(), comp);

        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(v[0].second);

        int len = pq.size();
        ans = max(ans, len);

        for (int i = 1; i < N; i++)
        {
            while (!pq.empty() && v[i].first >= pq.top())
            {
                pq.pop();
            }
            pq.push(v[i].second);
            len = pq.size();
            ans = max(ans, len);
        }

        return ans;
    }
};