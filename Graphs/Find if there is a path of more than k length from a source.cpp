#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
    int V;
    list<pair<int, int>> *adj;
    bool pathMoreThanKUtil(int src, int k, vector<bool> &path);

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<iPair>[V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    bool dfs(vector<bool>& visited, int src, int k) {
        visited[src] = true;

        if(k <= 0) return true;

        for(auto nbr : this->adj[src]) {
            if(!visited[nbr.first]) {
                if(dfs(visited, nbr.first, k-nbr.second)) return true;
            }
        }

        visited[src] = false;
        return false;
    }

    bool pathMoreThanK(int src, int k)
    {
        vector<bool> visited(this->V, false);

        return dfs(visited, src, k);
    }
};

int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 65;
    g.pathMoreThanK(src, k) ? cout << "Yes\n" : cout << "No\n";

    k = 55;
    g.pathMoreThanK(src, k) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
