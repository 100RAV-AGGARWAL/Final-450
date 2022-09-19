class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        long long minDiff = INT_MAX;
        
        for(long long i=0; i<=n-m; i++) {
            minDiff = min(minDiff, a[m+i-1]-a[i]);
        }
        
        return minDiff;
    }   
};