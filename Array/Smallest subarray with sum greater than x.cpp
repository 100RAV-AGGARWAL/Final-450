class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here  
        int sum=0, i=0, j=0;
        int mn = INT_MAX;
        
        while(i<n || j<n) {
            if(sum <= x && i<n) {
                sum += arr[i];
                i++;
            } else if(sum > x) {
                mn = min(mn, i-j-1);
                sum -= arr[j];
                j++;
            } else {
                break;
            }
        }
        return mn+1;
    }
};