#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int start, finish, profit;
};

bool comp(Job &a, Job &b) {
    return a.finish < b.finish;
}

//TOP DOWN
int latestNonconflict(Job arr[], int i) {
    for(int j=i-1; j>=0; j--) {
        if(arr[j].finish < arr[i].start) return j;
    }

    return -1;
}

int findMaxProfit2(Job arr[], int n)
{
    sort(arr, arr+n, comp);

    vector<int> dp(n, 0);

    dp[0] = arr[0].profit;

    for(int i=1; i<n; i++) {
        int profit = arr[i].profit;
        int idx = latestNonconflict(arr, i);

        if(idx != -1) profit += dp[idx];

        dp[i] = max(profit, dp[i-1]);
    }

    return dp[n-1];
}

//MEMOIZATION - TLE ON LEETCODE
int solve(Job arr[], int n, int curr, int prev, vector<vector<int>> &dp) {
    if(curr == n) return 0;

    if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

    int take=0, nottake=0;

    if(prev == -1 || arr[curr].start >= arr[prev].finish) {
        take = arr[curr].profit + solve(arr, n, curr+1, curr, dp);
    }

    nottake = solve(arr, n, curr+1, prev, dp);

    return dp[curr][prev+1] = max(take, nottake);
}

int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr+n, comp);

    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    return solve(arr, n, 0, -1, dp);
}



int main()
{
    Job arr[] = {{3, 10, 20},
                 {1, 2, 50},
                 {6, 19, 100},
                 {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The optimal profit is "
         << findMaxProfit(arr, n);
    return 0;
}
