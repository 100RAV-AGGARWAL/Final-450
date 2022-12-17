#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

// Adjacency List to store the graph
vector<int> graph[maxN];

// Function to add directed edge
// between two vertices
void addEdge(int u, int v)
{
	// Insert edge from u to v
	graph[u].push_back(v);
}

void topoSort(int i, vector<bool>& vis, stack<int>& st) {
	vis[i] = true;

	for(auto it : graph[i]) {
		if(!vis[it]) {
			topoSort(it, vis, st);
		}
	}

	st.push(i);
}

void shortestPathFromSrc(int n, int m, int src)
{
    //topological sort
	stack<int> st;
	vector<bool> vis(n+1, false);

	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			topoSort(i, vis, st);
		}
	}

	//shortest path calculation
	vector<int> dist(n+1, INT_MAX);
	dist[src] = 0;

	while(!st.empty()) {
		int top = st.top();
		st.pop();

		if(dist[top] != INT_MAX) {
			for(auto it : graph[top]) {
				dist[it] = min(dist[it], dist[top] + 1);
			}
		}
	}

	//print
	for(auto i : dist) {
		cout<<i<<" ";
	}
}

// Driver Code
int main()
{
	// Given Nodes N and edges M
	int n, m;
	n = 10;
	m = 13;

	// Given Directed Edges of graph
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(2, 8);
	addEdge(2, 9);
	addEdge(3, 6);
	addEdge(4, 6);
	addEdge(4, 8);
	addEdge(5, 8);
	addEdge(6, 7);
	addEdge(7, 8);
	addEdge(8, 10);

	// Function Call
	shortestPathFromSrc(n, m, 1);
	return 0;
}
