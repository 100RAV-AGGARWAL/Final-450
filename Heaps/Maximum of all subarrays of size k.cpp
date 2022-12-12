class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        priority_queue<pair<int, int>> pq;
        
        for(int i=0; i<k; i++) {
            pq.push({arr[i], i});
        }
        
        vector<int> ans;
        ans.push_back(pq.top().first);
        
        for(int i=k; i<arr.size(); i++) {
            pq.push({arr[i], i});
            while(pq.top().second <= i-k) {
                pq.pop();
            }
            
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};