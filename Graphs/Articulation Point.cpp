#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &low, vector<int> &disc, vector<bool> &vis, int &timer, vector<int> &ap) {
    vis[node] = true;
    disc[node] = low[node] = timer++;
    
    int child = 0;

    for(auto nbr : adj[node]) {
        if(nbr == parent) {
            continue;
        }

        if(!vis[nbr]) {
            dfs(nbr, node, adj, low, disc, vis, timer, ap);
            low[node] = min(low[node], low[nbr]);

            //Articulation point check
            if(low[nbr] >= disc[node] && parent != -1) {
                ap[node] = 1;
            }
            child++;
        } else {
            //back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if(parent == -1 && child > 1) {
        ap[node] = 1;
    }
}


int main() {
    int V = 5, E = 5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 3});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({3, 4});
    edges.push_back({1, 2});

    vector<vector<int>> adj(V, vector<int>());

    for(auto it : edges) {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    int timer = 0, parent = -1;
    vector<int> disc(V, -1), low(V, -1), ap(V, 0);
    vector<bool> vis(V, false);

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            dfs(i, parent, adj, low, disc, vis, timer, ap);
        }
    }

    for(int i=0; i<V; i++) {
        if(ap[i] != 0) cout<<i<<" ";
    }
    cout<<endl;
}