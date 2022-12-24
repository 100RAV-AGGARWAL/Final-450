class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);

        //{stops, {node, dist}}
        queue<pair<int, pair<int, int>>> q;

        dist[src]=0;
        q.push({0, {src, 0}});

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            int stops = top.first;
            int node = top.second.first;
            int distance = top.second.second;

            if(stops > k) continue;

            for(auto it : adj[node]) {
                int nbr = it.first;
                int wt = it.second;

                if(dist[nbr] > distance + wt && stops <= k) {
                    dist[nbr] = distance + wt;
                    q.push({stops+1, {nbr, dist[nbr]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
        
    }
};

// TIME LIMIT EXCEEDED
// class Solution {
// public:
//     void dfs(int i, int dst, vector<vector<pair<int, int>>> adj, vector<bool>& vis, int k, int ans, int& minans) {
//         if(i == dst && k >= -1) {
//             minans = min(minans, ans);
//             return;
//         } else if(k <= -1 && i != dst) {
//             return;
//         }

//         vis[i] = true;

//         for(auto nbr : adj[i]) {
//             if(!vis[nbr.first]) {
//                 if(ans+nbr.second < minans)
//                 dfs(nbr.first, dst, adj, vis, k-1, ans + nbr.second, minans);
//             }
//         }

//         vis[i] = false;

//     }

//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<pair<int, int>>> adj(n);

//         for(auto it : flights) {
//             adj[it[0]].push_back({it[1], it[2]});
//         }

//         vector<bool> vis(n, false);
//         int minans = INT_MAX;

//         dfs(src, dst, adj, vis, k, 0, minans);

//         if(minans == INT_MAX) return -1;

//         return minans;
        
//     }
// };