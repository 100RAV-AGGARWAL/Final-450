class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a, a+n);
        
        long long int sum=0;
        long long int minPos = INT_MAX;
        
        for(int i=0; i<n; i++) { 
            if(a[i] < 0) {
                if(k) {
                    sum += a[i]*-1;
                    k--;
                    minPos = min(minPos, (a[i]*-1));
                } else {
                    sum += a[i];
                }
            } else {
                minPos = min(minPos, a[i]);

                sum += a[i];
            }
            
        }
        
        if(k && k%2 != 0) {
            sum -= 2*minPos;
        }
        
        return sum;
    
    }
};