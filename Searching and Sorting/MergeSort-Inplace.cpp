class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
         int maxEl = max(arr[mid], arr[r]) + 1;
         
         int i=l, j=mid+1, k=l;
         
         while(i <= mid && j <= r && k <= r) {
            int x = arr[i] % maxEl;
            int y = arr[j] % maxEl;
            
            if(x <= y) {
                arr[k++] += (x * maxEl);
                i++;
            } else {
                arr[k++] += (y * maxEl);
                j++;
            }
         }
         
         while(i <= mid) {
            int x = arr[i] % maxEl;
            arr[k] += (x * maxEl);
            i++;
            k++; 
         }
         
         while(j <= r) {
            int y = arr[j] % maxEl;
            arr[k] += (y * maxEl);
            j++;
            k++; 
         }
         
         for(int i=l; i<=r; i++) {
             arr[i] = arr[i] / maxEl;
         }
         
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l >= r) {
            return;
        }
        
        int mid = (l+r)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};