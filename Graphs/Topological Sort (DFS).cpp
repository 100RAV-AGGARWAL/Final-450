class Solution
{
public:
	// Function to return list containing vertices in Topological order.
	void dfsTopo(int i, vector<int> adj[], vector<bool> &vis, stack<int> &st)
	{
		vis[i] = true;

		for (auto it : adj[i])
		{
			if (!vis[it])
			{
				dfsTopo(it, adj, vis, st);
			}
		}

		st.push(i);
	}

	vector<int> topoSort(int V, vector<int> adj[])
	{
		// code here
		vector<int> ans;
		vector<bool> vis(V, false);
		stack<int> st;

		for (int i = 0; i < V; i++)
		{
			if (!vis[i])
			{
				dfsTopo(i, adj, vis, st);
			}
		}

		while (!st.empty())
		{
			ans.push_back(st.top());
			st.pop();
		}

		return ans;
	}
};