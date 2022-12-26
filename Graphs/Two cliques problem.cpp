#include<bits/stdc++.h>
using namespace std;

const int V = 5;

bool dfs(int node, vector<vector<int>> adj, vector<bool> &vis, vector<int> &color) {
    vis[node] = true;

    for(auto nbr : adj[node]) {
        if(!vis[nbr]) {
            color[nbr] = !color[node];
            if(!dfs(nbr, adj, vis, color)) return false;
        } else if(node != nbr && color[node] == color[nbr]) return false;
    }

    return true;
}

bool isBipartite(int GC[][V]) {
    vector<bool> vis(V, false);
    vector<int> color(V, 0);

    vector<vector<int>> adj(V);

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(GC[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            if(!dfs(i, adj, vis, color)) return false;
        }
    }

    return true;
}

bool canBeDividedinTwoCliques(int G[][V]) {
    int GC[V][V];

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            GC[i][j] = ((i==j) ? 0 : !G[i][j]);
        }
    }

    return isBipartite(GC);
}

int main() {
    int G[][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };

    canBeDividedinTwoCliques(G) ? cout << "Yes" : cout << "No";
    return 0;
}