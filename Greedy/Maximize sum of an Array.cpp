class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        sort(a, a+n);
        long int sum = 0;
        int mod = 1000000007;
        
        for(int i=0; i<n; i++) {
            sum += ((long)a[i]*i)%mod;
        }
        
        return (int)(sum % mod);
    }
};