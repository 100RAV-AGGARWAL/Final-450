class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int pos=0, i=0, j=0;
        
        if(k < 0) return -1;
        
        arr1[n] = INT_MAX;
        arr2[m] = INT_MAX;
        
        while(i<=n && j<=m) {
            if(arr1[i] <= arr2[j]) {
                pos++;
                if(pos == k) return arr1[i];
                i++;
            } else {
                pos++;
                if(pos == k) return arr2[j];
                j++;
            }
        }
        
        return -1;
    }
};