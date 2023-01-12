#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> A, int k, int n, int i, vector<vector<int>> &dp) {
    if(i == n || k == 0) return 0;

    if(dp[i][k] != -1) return dp[i][k];

    int take = 0, nottake = 0;

    if(A[i] <= k) {
        take = 1 + solve(A, k/A[i], n, i+1, dp);
    }

    nottake = solve(A, k, n, i+1, dp);

    return dp[i][k] = take + nottake;
}

int productSubSeqCount(vector<int> A, int k) {
    int n = A.size();

    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

    return solve(A, k, n, 0, dp);
}

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << productSubSeqCount(A, k) << endl;
}