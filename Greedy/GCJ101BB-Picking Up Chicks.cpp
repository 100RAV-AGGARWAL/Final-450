#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> v, vector<int> x, int n, int k, int b, int t) {
    int swaps = 0;
    int slow = 0;

    for(int i=n-1; i>=0; i--) {
        if(k <= 0) break;

        if(x[i]+(v[i]*t) < b) {
            slow++;
        } else {
            swaps += slow;
            k--;
        }
    }

    if(k != 0) return -1;

    return swaps;
}

int main() {
    int t;
    cin>>t;

    int temp=0;
    while(temp++<t) {
        int n, k, b, t;
        cin>>n>>k>>b>>t;

        vector<int> v(n), x(n);

        for(int i=0; i<n; i++) {
            cin>>x[i];
        }
        for(int i=0; i<n; i++) {
            cin>>v[i];
        }

        int ans = minSwaps(v, x, n, k, b, t);

        cout<<"Case #" << temp <<": ";

        if(ans == -1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
}