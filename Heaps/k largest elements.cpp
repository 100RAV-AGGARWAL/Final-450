class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int> pq;
	    vector<int> ans;
	    
	    for(int i=0; i<n; i++) {
	        pq.push(arr[i]);
	    }
	    
	    for(int i=0; i<k; i++) {
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    
	    return ans;
	}

};