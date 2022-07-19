class Solution{
public:
    int count1(vector<int> arr, int m) {
        for(int i=0; i<m; i++) {
            if(arr[i] == 1)
                return m-i;
        }
        
        return 0;
    }
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ind = -1, max1=0;
	    
	    for(int i=0; i<n; i++) {
	        int cnt = count1(arr[i], m);
	        
	        if(cnt > max1) {
	            max1 = cnt;
	            ind = i;
	        }
	    }
	    
	    return ind;
	}

};