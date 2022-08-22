class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here
            int i=0;
            if(arr1[n-1] <= arr2[0])
                return;
            
            while(i<n) {
                if(arr1[i] > arr2[0]) {
                    swap(arr1[i], arr2[0]);
                    sort(arr2, arr2+m);
                    
                    if(arr1[n-1] <= arr2[0])
                        break;
                }
                i++;
            }
        } 
};