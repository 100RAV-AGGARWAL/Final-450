#include<bits/stdc++.h>
using namespace std;

struct Job {
    int start, end, profit;
};

int compareEnd(Job a, Job b) {
    return a.end < b.end;
}

int findNonConflictingJob(Job arr[], int i) {
    // for(int j=i-1; j>=0; j--) {
    //     if(arr[j].end <= arr[i].start) {
    //         return j;
    //     }
    // }
    // return -1;

    int high = i, low = 0;

    while(low <= high) {
        int mid = (high+low)/2;

        if(arr[mid].end <= arr[i].start) {
            if(arr[mid+1].end <= arr[i].start) 
                low = mid+1;
            else 
                return mid;
        } else {
            high = mid-1;
        }
    }

    return -1;
}



int maxProfit(Job arr[], int n) {
    if(n == 1) return arr[0].profit;

    sort(arr, arr+n, compareEnd);

    int dp[n];
    dp[0] = arr[0].profit;

    for(int i=1; i<n; i++) {
        int profit = arr[i].profit;

        int ind = findNonConflictingJob(arr, i);
        if(ind != -1) {
            profit += arr[ind].profit;
        }

        dp[i] = max(profit, dp[i-1]);
    }

    return dp[n-1];
}

int main() {
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {2, 7, 170}, {2, 100, 100}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << maxProfit(arr, n);
    return 0;
}