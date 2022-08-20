vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans(2, -1);
    
    for(int i=0; i<n-1; i++) {
        if(arr[i] == x && ans[0] == -1) {
            ans[0] = i;
        }
        if(arr[i] == x && arr[i+1] != x) {
            ans[1] = i;
        }
    }
    
    if(arr[n-1] == x) {
        if(ans[0] == -1) 
            ans[0] = n-1;
            
        ans[1]=n-1;
    }
    
    return ans;
    
}