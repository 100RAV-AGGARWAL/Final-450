#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int maxTime(int H, int A, int cnt, bool flag) {
    if(H<=0 || A<=0) {
        return cnt;
    }

    if(dp[H][A] != -1) return dp[H][A];

    if(flag) dp[H][A] = max(dp[H][A], maxTime(H+3, A+2, cnt+1, !flag));

    return dp[H][A] = max(dp[H][A], max(maxTime(H-5, A-10, cnt+1, !flag), maxTime(H-20, A+5, cnt+1, !flag)));
}

// TLE
// int maxTime(int H, int A, int option) {

//     if(option==1) {
//         H += 3;
//         A += 2;
//     } else if(option == 2) {
//         H -= 5;
//         A -= 10;
//     } else {
//         H -= 20;
//         A += 5;
//     }

//     if(H<=0 || A<=0) return 0;

//     if(option == 1) {
//         return max(maxTime(H, A, 2), maxTime(H, A, 3))+1;
//     } else {
//         return maxTime(H, A, 1)+1;
//     }

// }

int main() {
    int t;
    cin>>t;

    while(t--) {
        int H, A;
        cin>>H>>A;

        // cout<<maxTime(H, A, 1)<<endl;
        bool flag = true;
        memset(dp, -1, sizeof dp);
        cout<<maxTime(H, A, -1, flag)<<endl;
    }
}