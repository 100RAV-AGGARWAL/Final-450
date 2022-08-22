class Solution{
    public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] != b[0]) {
            return a[0] > b[0];
        }
        return a[1] < b[1];
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> v(n);
        int ans[n];
        for(int i=0; i<n; i++) {
            ans[i] = arr[i];
        }
        
        for(int i=0; i<n; i++) {
            int k = __builtin_popcount(arr[i]);
            v[i] = {k, i};
        }
        
        sort(v.begin(), v.end(), comp);
        for(int i=0; i<n; i++) {
            arr[i] = ans[v[i][1]];
        }
    }
};