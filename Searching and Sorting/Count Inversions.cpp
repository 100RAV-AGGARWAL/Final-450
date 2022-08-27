//Binary Search Approach
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        int inv=0;
        vector<int> temp;
        temp.push_back(arr[n-1]);
        
        for(int i=n-2; i>=0; i--) {
            int st = 0, end = temp.size()-1;
            while(st <= end) {
                int mid = (st+end)/2; 
                
                if(temp[mid] >= arr[i]) {
                    end = mid-1;
                } else {
                    inv += (mid-st+1);
                    st = mid+1;
                }
            }
            
            temp.push_back(arr[i]);
            sort(temp.begin(), temp.end());
        }
        
        return inv;
    }

};

//Efficient approach : Merge Sort
 typedef long long ll;
 ll merge(ll arr[], ll lo, ll mid, ll hi){
        
        ll left = lo, right = mid+1, invc= 0;
        for(ll left = lo; left <= mid; left++){
            while(right <= hi and arr[left] > arr[right])right++;
            invc += right - mid - 1;
        }
        
        ll tmp[hi-lo+1];
        ll newId = 0;
        left = lo, right = mid+1;
        while(left <= mid and right <= hi){
            if(arr[left] > arr[right]){
                tmp[newId++] = arr[right++];
            }else{
                tmp[newId++] = arr[left++];
            }
        }
        
        while(left <= mid)tmp[newId++] = arr[left++];
        while(right <= hi)tmp[newId++] = arr[right++];
        
        for(int i=lo; i <= hi; i++){
            arr[i] = tmp[i-lo];
        }
        
        return invc;
        
    }
    ll mergeSort(ll arr[], ll lo, ll hi){
        ll inv = 0;
        if(lo >= hi)return 0;
        
        ll mid = lo + (hi - lo)/2;
        inv += mergeSort(arr,lo,mid);
        inv += mergeSort(arr,mid+1,hi);
        inv += merge(arr,lo,mid,hi);
        
        return inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
        return mergeSort(arr,0,N-1);
    }