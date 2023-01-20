class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here
        if(n==0) return 0;

        int count = 0;

        while(n!=0){

           if((n&1)==1)count++;

           if(count>1)return 0;

           n = n>>1;

        }

        return 1;
        
    }
};