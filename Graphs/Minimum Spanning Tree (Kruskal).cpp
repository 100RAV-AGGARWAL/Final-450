#define vec vector<int>
class Solution
{
public:
    int findParent(int node, vector<int> &parent)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(node, parent);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        // int pu = findParent(u, parent);
        // int pv = findParent(v, parent);

        if(pu == pv) return;

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj)
    {
        // code here
        int ans = 0;
        vector<int> parent(V, -1), rank(V, 0);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        sort(adj.begin(), adj.end(), cmp);

        for (auto ad : adj)
        {
            int pu = findParent(ad[0], parent);
            int pv = findParent(ad[1], parent);

            if (pu != pv)
            {
                ans += ad[2];
                unionSet(pu, pv, parent, rank);
            }
        }

        return ans;
    }
};