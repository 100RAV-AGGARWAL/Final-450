class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i = N-2;
        while(i >= 0 && arr[i] >= arr[i+1]) {
            i--;
        }
        
        if(i != -1) {
            for(int j=N-1; j>=i; j--) {
                if(arr[j] > arr[i]) {
                    swap(arr[j], arr[i]);
                    break;
                }
            }
        }
        
        reverse(arr.begin()+i+1, arr.end());
        return arr;
    }
};