// C++ program to find maximum cash flow among a set of persons
#include<bits/stdc++.h>
using namespace std;

// Number of persons (or vertices in the graph)
#define N 3

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

void minCashFlowRec(vector<pair<int, int>> amount)
{
	sort(amount.begin(), amount.end(), comp);

	if(amount[0].first == 0 && amount[N-1].first == 0) return;

	int mn = min(-(amount[0].first), amount[N-1].first);

	amount[0].first += mn;
	amount[N-1].first -= mn;

    cout << "Person " << amount[N-1].second << " pays " << mn << " to " << "Person " << amount[0].second << endl;

	minCashFlowRec(amount);
    
}

void minCashFlow(int graph[][N]) {
	vector<pair<int, int>> v(N, {0,0});

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			v[i].first += (graph[i][j] - graph[j][i]);
			v[i].second = i;
		}
	}

	minCashFlowRec(v);
}

// Driver program to test above function
int main()
{
	// graph[i][j] indicates the amount that person i needs to
	// pay person j
	int graph[N][N] = { {0, 1000, 2000},
						{0, 0, 5000},
						{0, 0, 0},};

	// Print the solution
	minCashFlow(graph);
	return 0;
}
