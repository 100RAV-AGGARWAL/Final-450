class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<int> &color, vector<bool> &visited)
    {
        visited[node] = true;

        for (auto nbr : adj[node])
        {
            if (!visited[nbr])
            {
                color[nbr] = !color[node];
                if (!dfs(nbr, adj, color, visited))
                    return false;
            }
            else if (node != nbr && color[node] == color[nbr])
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        vector<int> color(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (!dfs(i, adj, color, visited))
                    return false;
            }
        }
        return true;
    }
};