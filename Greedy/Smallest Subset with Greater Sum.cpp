class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
        sort(arr.begin(), arr.end());
        
        int i=0, j=n-1;
        long long int lsum = arr[i], rsum = arr[j];
        
        while(i < j) {
            if(rsum > lsum) {
                lsum += arr[++i];
            } else {
                if(i == j-1) { 
                    lsum -= arr[i--];
                }
                rsum += arr[--j];
            }
        }
        
        return n-j;
    }
};