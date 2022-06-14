long long int inversionCount(long long arr[], long long n)
{
    // Your Code Here
    int inversion=0;
    
    for(int i=0; i<n-1; i++) {
        int inv=0;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[i])
                inv++;
        }
        
        if(arr[i] == arr[i+1]) {
            inv*=2;
            i++;
        }
        
        inversion += inv;
    }
    
    return inversion;
}