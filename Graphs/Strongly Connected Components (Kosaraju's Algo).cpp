class Solution
{
public:
    void dfsTopo(int i, vector<int> adj[], vector<bool> &vis, stack<int> &st)
    {
        vis[i] = true;

        for (auto nbr : adj[i])
        {
            if (!vis[nbr])
            {
                dfsTopo(nbr, adj, vis, st);
            }
        }

        st.push(i);
    }

    void topoSort(int V, vector<int> adj[], stack<int> &st)
    {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsTopo(i, adj, vis, st);
            }
        }
    }

    void dfs(int i, vector<bool> &vis, vector<int> adj[])
    {
        vis[i] = true;

        for (auto nbr : adj[i])
        {
            if (!vis[nbr])
            {
                dfs(nbr, vis, adj);
            }
        }
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // code here
        stack<int> st;
        topoSort(V, adj, st);

        vector<int> t[V];
        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                t[j].push_back(i);
            }
        }

        vector<bool> vis(V, false);
        int ans = 0;

        while (!st.empty())
        {
            int i = st.top();
            st.pop();

            if (!vis[i])
            {
                ans++;
                dfs(i, vis, t);
            }
        }

        return ans;
    }
};