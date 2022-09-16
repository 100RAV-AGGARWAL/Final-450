class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	// vector<pair<int, int>> v, plat;
    	// for(int i=0; i<n; i++) {
    	//     v.push_back({arr[i], dep[i]});
    	// }
    	
    	// sort(v.begin(), v.end(), comp);
    	
    	// plat.push_back(v[0]);
    	
    	// for(int i=1; i<n; i++) {
    	//     bool flag = false;
    	//     for(int j=plat.size()-1; j>=0; j--) {
    	//         if(v[i].first > plat[j].second) {
    	//             flag = true;
    	//             plat[j] = v[i];
    	//             break;
    	//         }
    	//     }
    	    
    	//     if(!flag) plat.push_back(v[i]);
    	// }
    	
    	// return plat.size();
        
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int ans = 0, i = 0, j = 0, curr = 0;
        
        while(i<n && j<n) {
            if(arr[i] <= dep[j]) {
                i++;
                curr++;
            } else {
                j++;
                curr--;
            }
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};