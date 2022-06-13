#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   int getMinDiff(int a[], int n, int k) {
        // code here
        sort(a, a+n);
        int ans = a[n-1] - a[0];
        int Min, Max;
        int smallest = a[0]+k;
        int largest = a[n-1]-k;
        
        for(int i =1; i<n; i++) {
            if(a[i] >= k && a[n-1] >=k) {
              Min = min(smallest, a[i]-k);
              Max = max(largest, a[i-1]+k);
               
              ans = min(ans, Max-Min);
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}