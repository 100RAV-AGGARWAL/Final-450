#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Graph
{
    int V;
    list<pair<int, int>> *graph;

public:
    Graph(int V)
    {
        this->V = V;
        graph = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w)
    {
        graph[u].push_back(make_pair(v, w));
    }

    vector<int> shortestPath(int src)
    {
        set<pair<int, int>> s;
        vector<int> dist(V, INF);

        s.insert({0, src});
        dist[src] = 0;

        while (!s.empty())
        {
            auto top = *(s.begin());
            s.erase(s.begin());

            int u = top.second;

            for (auto nbr : graph[u])
            {
                int v = nbr.first;
                int w = nbr.second;

                if (dist[v] > dist[u] + w)
                {
                    if (dist[v] != INF)
                    {
                        s.erase(s.find({dist[v], v}));
                    }

                    dist[v] = dist[u] + w;
                    s.insert({dist[v], v});
                }
            }
        }
        return dist;
    }

    Graph modifyGraph(int edge[][2], int E, int V)
    {
        Graph g(V);

        for (int i = 0; i < E; i++)
        {
            g.addEdge(edge[i][0], edge[i][1], 0);
            g.addEdge(edge[i][1], edge[i][0], 1);
        }

        return g;
    }

    int getMinEdgeReversal(int edge[][2], int E, int V, int src, int dest)
    {
        Graph g = modifyGraph(edge, E, V);

        vector<int> dist = g.shortestPath(src);

        if (dist[dest] == INF)
        {
            return -1;
        }
        else
        {
            return dist[dest];
        }
    }
};

int main()
{
    int V = 7;
    Graph g(V);

    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);

    int minEdgeToReverse = g.getMinEdgeReversal(edge, E, V, 0, 6);

    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not Possible." << endl;

    return 0;
}
