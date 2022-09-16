// CPP to design platform for maximum stoppage
#include <bits/stdc++.h>
using namespace std;

// number of platforms and trains
#define n 2
#define m 5

bool comp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

// function to calculate maximum trains stoppage
int maxStop(int arr[][3])
{
    map<int, pair<int, int>> mp;
    vector<vector<int>> v;

    for(int i=0; i<m; i++) {
        v.push_back({arr[i][0], arr[i][1], arr[i][2]});
    }
    sort(v.begin(), v.end(), comp);

    int ans = 0;

    for(int i=0; i<m; i++) {
        if(mp.find(v[i][2]) == mp.end()) {
            ans++;
            mp[v[i][2]] = {v[i][0], v[i][1]};
        } else {
            if(v[i][0] > mp[v[i][2]].second) {
                ans++;
                mp[v[i][2]] = {v[i][0], v[i][1]};
            }
        }
    }

    return ans;

    //N^2
    /* 
        for (int i = 0; i < m; i++)
            vect[arr[i][2]].push_back(
                make_pair(arr[i][1], arr[i][0]));
    
        
        for (int i = 0; i <= n; i++)
            sort(vect[i].begin(), vect[i].end());
        
        int count = 0;
        for (int i = 0; i <= n; i++) {
            if (vect[i].size() == 0)
                continue;
    
            int x = 0;
            count++;
            for (int j = 1; j < vect[i].size(); j++) {
                if (vect[i][j].second >=
                                vect[i][x].first) {
                    x = j;
                    count++;
                }
            }
        }
        return count;
    */
}

// driver function
int main()
{
	int arr[m][3] = { 1000, 1030, 1,
					1010, 1020, 1,
					1025, 1040, 1,
					1130, 1145, 2,
					1130, 1140, 2 };
	cout << "Maximum Stopped Trains = "
		<< maxStop(arr);
	return 0;
}
