class Solution {
public:
    static bool sortCol(vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0];    
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end(), sortCol);
        
        int start = intervals[0][0], end = intervals[0][1];
        int n = intervals.size();
        
        for(int i=1; i<n; i++) {
            if(intervals[i][0] >= start && intervals[i][0] <= end) {
                if(intervals[i][1] > end)
                    end = intervals[i][1];
            } else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        ans.push_back({start, end});
        
        return ans;
    }
};