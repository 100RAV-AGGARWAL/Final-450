class Solution 
{
    public:
    int isPlacementPossible(int a[], int n, int m, int gap) {
        int pages = 0, students=1;
        
        for(int i=0; i<n; i++) {
            if(a[i] > gap) return false;
            
            if(a[i] + pages > gap) {
                students++;
                pages = a[i];
            } else {
                pages += a[i];
            }
            
            if(students > m) return false;
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int totalPages=0;
        
        if(M > N) {
            return -1;
        }
        
        for(int i=0; i<N; i++) {
            totalPages += A[i];  
        }
        
        int start=A[0], end = totalPages;
        int ans = -1;
        while(start <= end) {
            int mid = (start+end)/2;
            
            if(isPlacementPossible(A, N, M, mid)) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        
        return ans;
    }
};