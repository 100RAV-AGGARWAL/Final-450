#include<bits/stdc++.h>
using namespace std;
#define N 3

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

void util(vector<pair<int, int>> &v) {
    sort(v.begin(), v.end(), comp);

    if(v[0].first == 0 && v[N-1].first == 0) return;

    int minamt = min(-v[0].first, v[N-1].first);

    v[0].first += minamt;
    v[N-1].first -= minamt;

    cout << "Person " << v[0].second << " pays " << minamt << " to " << "Person " << v[N-1].second << endl;

    util(v);
}

void minCashFlow(int graph[N][N]) {
    vector<pair<int, int>> v(N, {0, 0});

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            v[i].first += (graph[j][i]-graph[i][j]);
            v[i].second = i;
        }
    }

    util(v);
}

int main() {
	int graph[N][N] = { {0, 1000, 2000},
						{0, 0, 5000},
						{0, 0, 0},};

	minCashFlow(graph);
	return 0;
}