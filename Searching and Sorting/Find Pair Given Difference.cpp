bool findPair(int arr[], int size, int n){
    //code
    unordered_map<int, int> m;
    
    for(int i=0; i<size; i++) {
        m[arr[i]]++;
    }
    
    for(int i=0; i<size; i++) {
        if(n == 0) {
            if(m[abs(n-arr[i])] > 1) {
                return true;
            }
        } else {
            if(m[abs(n-arr[i])] > 0)
                return true;
        }
    }
    
    return false;
}