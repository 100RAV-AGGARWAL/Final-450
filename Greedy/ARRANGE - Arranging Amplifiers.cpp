#include<bits/stdc++.h>
using namespace std;

bool comp(int a , int b) {
    return a>b;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int N;
        cin>>N;

        vector<int> v(N);

        for(int i=0; i<N; i++) {
            cin>>v[i];
        }

        sort(v.begin(), v.end());

        int i=0;
        while(v[i] == 1) {
            cout<<v[i]<<" ";
            i++;
        }

        if(i == N-2 && v[i] == 2 && v[i+1] == 3) cout<<v[i]<<" "<<v[i+1];
        else {
            for(int j=N-1; j>=i; j--) {
                cout<<v[j]<<" ";
            }
        }
        cout<<endl;

    }
}