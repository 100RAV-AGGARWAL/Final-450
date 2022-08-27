#include<bits/stdc++.h>
using namespace std;

void calcSubsets(vector<int>& arr, int st, int end, vector<int>& subsetArr, int sum) {
    if(st > end) {
        subsetArr.push_back(sum);
        return;
    }

    calcSubsets(arr, st+1, end, subsetArr, sum);
    calcSubsets(arr, st+1, end, subsetArr, sum + arr[st]);
}

int maxSubsets(vector<int>& arr, int a, int b, int n) {
    vector<int> s1, s2;
    calcSubsets(arr, 0, (n/2)-1, s1, 0);
    calcSubsets(arr, n/2, n-1, s2, 0);

    int ans = 0;

    sort(s2.begin(), s2.end());
    for(int i=0; i<s1.size(); i++) {
        int i1 = lower_bound(s2.begin(), s2.end(), a-s1[i]) - s2.begin();
        int i2 = upper_bound(s2.begin(), s2.end(), b-s1[i]) - s2.begin();
        ans += (i2 - i1);
    }

    return ans;
    
}

int main() {
    int n, a, b;
    cin>>n>>a>>b;

    vector<int> arr(n); 
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<maxSubsets(arr, a, b, n);
}