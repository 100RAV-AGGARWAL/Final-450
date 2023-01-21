class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	int i = 0, j = n-1, maxi=arr[n-1]+1; 
    	
    	for(int k=0; k<n; k++) {
    	    if(k%2) {
    	        arr[k] += ((arr[i]%maxi)*maxi);
    	        i++;
    	    } else {
    	        arr[k] += ((arr[j]%maxi)*maxi);
    	        j--;
    	    }
    	}
    	
    	for(i=0; i<n; i++) {
    	    arr[i] /= maxi;
    	}
    	
    }
};