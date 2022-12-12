class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        priority_queue<int> pq;
        
        for(auto i : a) {
            pq.push(i);
        }
        
        for(auto i : b) {
            pq.push(i);
        }
        
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};