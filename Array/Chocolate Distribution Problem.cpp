class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        long long minD = INT_MAX;
        for(int i=0; i<=n-m; i++) {
            minD = min(minD, a[i+m-1]-a[i]);
        }
        
        return minD;
    }   
};