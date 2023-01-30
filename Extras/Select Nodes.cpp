class Solution
{
public:
    int ans = 0;

    bool solve(vector<vector<int>> &adj, vector<bool> &visited, int node)
    {
        visited[node] = true;

        bool isParentSelected = false;

        for (auto nbr : adj[node])
        {
            if (!visited[nbr])
            {
                bool isChildSelected = solve(adj, visited, nbr);

                if (!isChildSelected)
                    isParentSelected = true;
            }
        }

        if (isParentSelected)
            ans++;

        return isParentSelected;
    }

    int countVertex(int N, vector<vector<int>> edges)
    {
        // code here
        vector<vector<int>> adj(N + 1);

        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(N + 1, false);

        solve(adj, visited, 1);

        return ans;
    }
};