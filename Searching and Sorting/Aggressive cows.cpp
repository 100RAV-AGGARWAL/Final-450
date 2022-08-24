#include<bits/stdc++.h>
using namespace std;

bool isPlacementPossible(vector<int>& arr, int cows, int gap) {
    int ind = arr[0];
    cows--;

    for(int i=1; i<arr.size(); i++) {
        if(arr[i] - ind >= gap) {
            cows--;
            ind = arr[i];
            if(cows == 0) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& arr, int cows, int n) {
    sort(arr.begin(), arr.end());

    int start = arr[0], end = arr[n-1], ans;

    while(start <= end) {
        int mid = (start+end)/2;
        if(isPlacementPossible(arr, cows, mid)) {
            ans = mid;
            start = mid+1;
        } else {
            end = mid-1;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n, cows;
        cin >> n >> cows;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }

        cout << aggressiveCows(arr, cows, n)<< endl;
    }
}