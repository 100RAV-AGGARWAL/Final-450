#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;          // No. of vertices
    list<int> *adj; // Pointer to an array for adjacency lists

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool dfs(vector<bool>& vis, int node, int parent) {
        vis[node] = true;

        for(auto nbr : this->adj[node]) {
            if(!vis[nbr]) {
                if(!dfs(vis, nbr, node)) return false;
            } else if(nbr != parent){
                return false;
            }
        }

        return true;
    }

    bool isTree() {
        vector<bool> vis(V, false);
        
        int component = 0;

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                component++;

                if(component > 1) return false;

                if(!dfs(vis, i, -1)) return false;
            }
        }

        return true;
    }
};

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree() ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree() ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";

    return 0;
}
