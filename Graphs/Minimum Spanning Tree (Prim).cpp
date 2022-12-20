#define pr pair<int, int>
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        priority_queue<pr, vector<pr>, greater<pr>> pq;

        key[0] = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            mst[u] = true;

            for (auto it : adj[u])
            {
                if (mst[it[0]] == false && it[1] < key[it[0]])
                {
                    key[it[0]] = it[1];
                    pq.push({it[1], it[0]});
                }
            }
        }

        int ans = 0;
        for (auto i : key)
        {
            ans += i;
        }
        return ans;
    }
};