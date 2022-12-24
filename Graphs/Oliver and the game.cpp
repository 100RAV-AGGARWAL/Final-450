#include <bits/stdc++.h>
using namespace std;

int *In, *Out;

void dfs(vector<vector<int>> adj, int& count, int par, int node) {
	In[node] = count++;

	for(auto it : adj[node]) {
		if(it != par) {
			dfs(adj, count, node, it);
		}
	}

	Out[node] = count++;
}

int main() {
	int V;
	cin >> V;

	vector<vector<int>> adj(V+1);

	for(int i=0; i<V-1; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	In = new int[V+1];
	Out = new int[V+1];
	int count = 0;

	dfs(adj, count, 0, 1);

	int q;
	cin >> q;

	for(int i=0; i<q; i++) {
		int d, x, y;
		cin >> d >> x >> y;

		if(d == 1) {
			if(In[x] > In[y] && Out[x] < Out[y]) {
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		} else {
			if(In[x] < In[y] && Out[x] > Out[y]) {
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		}
	}
}