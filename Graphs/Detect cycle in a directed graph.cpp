class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool DFS(int i, vector<bool>& visited, vector<bool>& dfsVis, vector<int> adj[]) {
        visited[i] = true;
        dfsVis[i] = true;
        
        for(auto it : adj[i]) {
            if(!visited[it]) {
                if(DFS(it, visited, dfsVis, adj)) return true;
            } else if(dfsVis[it]) {
                return true;
            }
        }
        
        dfsVis[i] = false;
        return false;
    }
    
    bool isCyclicUsingDFS(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> dfsVis(V, false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(DFS(i, visited, dfsVis, adj)) return true;
            }
        }
        
        return false;
    }

    bool isCyclicUsingKahn(int V, vector<int> adj[])
    {
        // code here
        vector<int> indegree(V, 0);
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[front])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // If topological sort is valid then no of nodes 
        // is equal to cnt coz cycle is not present

        if(cnt != V) return true;
        else return false;
    }
};