long long maxArea(long long arr[], int len)
{
    // Your code goes here
    int l = 0, r = len-1;
    long long int maxAr = 0;
    
    while(l < r) {
        long long int area = (r - l) * min(arr[r], arr[l]);
        
        maxAr = max(maxAr, area);
        
        if(arr[r] < arr[l]) r--;
        else l++;
    }
    
    return maxAr;
}