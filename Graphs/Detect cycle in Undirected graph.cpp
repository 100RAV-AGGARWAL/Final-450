class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool BFS(int i, vector<bool>& visited, vector<int> adj[]) {
        queue<pair<int, int>> q;
        
        q.push({i, -1});
        visited[i] = true;
        
        while(!q.empty()) {
            int front = q.front().first;
            int parent = q.front().second;
            q.pop();
                
            for(auto it : adj[front]) {
                if(!visited[it]) {
                    q.push({it, front});
                    visited[it] = true;
                } else if(parent != it) {
                    return true;
                }
            }    
        }
        
        return false;
    }

    bool DFS(int i, int parent, vector<bool>& visited, vector<int> adj[]) {
        visited[i] = true;
        
        for(auto it : adj[i]) {
            if(!visited[it]) {
                if(DFS(it, i, visited, adj)) return true;
            } else if(it != parent) {
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(BFS(i, visited, adj)) return true;
            }
        }
        
        return false;
        
    }
};