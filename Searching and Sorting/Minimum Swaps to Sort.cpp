class Solution 
{
    public:
    static bool comp(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first < p2.first;
    }
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int ans=0;
	    int n = nums.size();
	    vector<pair<int, int>> v;
	    
	    for(int i=0; i<n; i++) {
	        v.push_back({nums[i], i});
	    }
	    
	    sort(v.begin(), v.end());
	    
	    for(int i=0; i<n; i++) {
	        if(i != v[i].second) {
	            swap(v[i], v[v[i].second]);
	            ans++;
	            i--;
	        }
	    }
	    return ans;
	}
};