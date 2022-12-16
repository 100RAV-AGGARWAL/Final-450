#include<bits/stdc++.h>
using namespace std;

template <typename T>

class UndirectedGraph {

    public:
    map<T, list<T>> adj;

    void addEdge(T u, T v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printAdjList() {
        for(auto it : adj) {
            cout<<it.first<<" -> ";

            for(auto j : it.second) {
                cout<<j<<", ";
            }

            cout<<endl;
        }
    }

};

int main() {
    UndirectedGraph<int> g;
    int V, E;
    cin>>V>>E;

    for(int i=0; i<E; i++) {
        int u, v;
        cin>>u>>v;

        g.addEdge(u, v);
    }

    g.printAdjList();
}