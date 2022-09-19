#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll findPenalty(vector<ll> X, vector<ll> Y, ll w, ll h, ll n) {
    if(n == 0) return w*h;
    ll maxW = 0, maxH = 0;

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    maxW = max(X[0]-1, w-X[n-1]);
    maxH = max(Y[0]-1, h-Y[n-1]);

    for(ll i=0; i<n-1; i++) {
        maxW = max(maxW, X[i+1]-X[i]-1);
        maxH = max(maxH, Y[i+1]-Y[i]-1);
    }

    return (maxW*maxH);
}

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n, w, h;
        cin>>w>>h>>n;

        vector<ll> X(n), Y(n);

        for(ll i=0; i<n; i++) {
            cin>>X[i];
            cin>>Y[i];
        }

        cout<<findPenalty(X, Y, w, h, n)<<endl;
    }
}