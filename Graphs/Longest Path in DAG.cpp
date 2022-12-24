#include <bits/stdc++.h>
using namespace std;

class AdjListNode
{
    int v;
    int weight;

public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};

class Graph
{
    int V; // No. of vertices'
    list<AdjListNode> *adj;

public:
    Graph(int V) // Constructor
    {
        this->V = V;
        adj = new list<AdjListNode>[V];
    }

    ~Graph() // Destructor
    {
        delete[] adj;
    }

    void addEdge(int u, int v, int weight)
    {
        AdjListNode node(v, weight);
        adj[u].push_back(node);
    }

    void topologicalSort(int node, vector<bool> &visited, stack<int> &st) {
        visited[node] = true;

        for(auto it : adj[node]) {
            int v = it.getV();
            if(!visited[v]) {
                topologicalSort(v, visited, st);
            }
        }

        st.push(node);
    }

    // Finds longest distances from given source vertex
    void longestPath(int s) {
        stack<int> st;
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                topologicalSort(i, visited, st);
            }
        }

        vector<int> dist(V, INT_MIN);
        dist[s] = 0;

        while(!st.empty()) {
            int top = st.top();
            st.pop();

            for(auto nbr : adj[top]) {
                int v = nbr.getV();
                int w = nbr.getWeight();

                if(dist[v] < dist[top] + w) {
                    dist[v] = dist[top] + w;
                }
            }
        }

        for(int i=0; i<V; i++) {
            if(dist[i] == INT_MIN)
                cout<<"INF ";
            else
                cout<<dist[i]<<" ";
        }

    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Following are longest distances from source vertex " << s << " \n";
    g.longestPath(s);

    return 0;
}