#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printVertexCover();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::printVertexCover()
{
    vector<bool> vis(V, false);

    for (int u = 0; u < V; u++)
    {
        if (!vis[u])
        {
            for (auto v : adj[u])
            {
                if (!vis[v])
                {
                    vis[u] = true;
                    vis[v] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (vis[i])
            cout << i << " ";
    }
}

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printVertexCover();

    return 0;
}
