class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        priority_queue<triplet, vector<triplet>, greater<triplet>> pq;
        vector<int> ans;
        
        for(int i=0; i<k; i++) {
            pq.push({arr[i][0], {i,0}});
        }
        
        while(!pq.empty()) {
            triplet curr = pq.top();
            pq.pop();
            
            ans.push_back(curr.first);
            
            int st = curr.second.first;
            int en = curr.second.second;
            
            if(en+1 < k) {
                pq.push({arr[st][en+1], {st, en+1}});
            }
        }
        
        return ans;
    }
};