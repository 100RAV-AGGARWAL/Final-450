#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int nPk(int n, int k) {
    if( n < k ) return 0;

    int dp[n+1][k+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=min(i, k); j++) {
            if(j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j] + j*dp[i-1][j-1]; 
            }

            dp[i][j+1] = 0;
        }
    }

    return dp[n][k];
}


int main() {
    int n, k;
    cin>>n>>k;

    cout<<nPk(n, k);
}