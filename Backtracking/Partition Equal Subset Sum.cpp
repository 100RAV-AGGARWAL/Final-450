class Solution{
public:
    bool util(int arr[], int N, int sum, int curr, int ind) {
        if(curr > sum/2 || ind >= N) return false;
        if(curr == sum/2) return true;
        
        for(int i=ind; i<N; i++) {
            curr += arr[i];
            if(util(arr, N, sum, curr, i+1)) return true;
            curr -= arr[i];
        }
        
        return false;
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++) sum+=arr[i];
        
        sort(arr, arr+N);
        if(sum%2 == 1) return 0;
        
        bool ans = util(arr, N, sum, 0, 0);
        return ans == true ? 1 : 0;
    }
}; 