class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here
        long long int ans = 1;
        sort(a.begin(), a.end());
        
        if(n==1) return a[n-1];
        if(n==2 && max(a[0], a[1]) == 0) return 0;
        
        int negcnt=0, mini = INT_MIN, mod=1000000007;
        int i=0;
        
        for(i=0; i<n; i++) {
            if(a[i] < 0) {
                negcnt++;
                mini = max(mini, a[i]);
            }
            if(a[i] != 0)
                ans *= (a[i]);
            ans = ans % mod;
        }
        
        if(negcnt%2 != 0) {
            ans /= mini;
        }
        
        return ans;
    }
};