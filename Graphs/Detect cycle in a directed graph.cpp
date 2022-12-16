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
    
    bool isCyclic(int V, vector<int> adj[]) {
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
};