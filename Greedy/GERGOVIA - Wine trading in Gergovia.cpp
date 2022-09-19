#include<bits/stdc++.h>
using namespace std;

long long int minWork(vector<int> v, int n) {
    long long int work=0;

    for(int i=1; i<n; i++) {
        v[i] += v[i-1];
        work += abs(v[i-1]);
    }

    return work;
}

int main() {
    while(true) {
        int n;
        cin>>n;

        if(n<=0) break;

        vector<int> v(n);
        for(int i=0; i<n; i++) {
            cin>>v[i];
        }

        cout<<minWork(v, n)<<endl;
    }
}