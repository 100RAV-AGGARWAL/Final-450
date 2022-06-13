#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // int max = INT_MIN;
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        
        int maxNow = INT_MIN, max_ending_here = 0;
        
        for(int i=0; i<n; i++) {
            max_ending_here += arr[i];
            if(max_ending_here > maxNow) {
                maxNow = max_ending_here;
            }
            
            if(max_ending_here < 0) {
                max_ending_here = 0;
            }
        }
        return maxNow;
    }
};

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}