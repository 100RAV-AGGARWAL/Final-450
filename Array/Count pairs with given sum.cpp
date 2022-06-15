class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        unordered_map<int, int> m;
        int ans=0;
        
        for(int i=0; i<n; i++) {
            if(m.find(k-arr[i]) != m.end()) {
                ans += m[k-arr[i]];
            }
            m[arr[i]]++;
        }
        return ans;
    }
};
