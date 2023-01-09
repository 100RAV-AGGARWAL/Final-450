class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n < 3) return n;
        
        long long f1 = 1, f2 = 2, mod = 1000000007;
        
        for(int i=3; i<=n; i++) {
            long long ans = (f2%mod + ((i-1)*f1)%mod)%mod;
            
            f1 = f2;
            f2 = ans;
        }
        
        return f2;
    }
};    