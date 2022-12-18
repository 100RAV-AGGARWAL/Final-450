class Solution {
public:
    // set<int> s;

    // int makeConnected(int n, vector<vector<int>>& connections) {
    //     int extra = 0;
    //     int disconnected = 0;

    //     for(auto it : connections) {
    //         for(auto i : it) {
    //             s.insert(i);
    //         }
    //     }

    //     for(int i=0; i<n; i++) {
    //         if(s.find(i) == s.end()) {
    //             disconnected++;
    //         }
    //     }    

    //     extra = (connections.size()-s.size()+1);

    //     if(disconnected <= extra) return disconnected;

    //     return -1;
    // }

    void dfs(vector<int> adj[], vector<bool>& visited, int i){
        
        if(visited[i]==false){
            visited[i]=true;
            
            for(auto itr:adj[i]){
                if(visited[itr]==false){
                    dfs(adj, visited, itr);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        
        if(connections.size()<n-1)
            return -1;
        
        vector<int> adj[n];
        
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        
        int res=0;
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                res+=1;
                dfs(adj, visited, i);
            }
        }
        
        return res-1;
    }
};