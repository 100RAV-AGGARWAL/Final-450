class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>> ans;
         stack<int> st, en;
         int start, end;
         
         sort(intervals.begin(), intervals.end());
         
         for(int i=0; i<intervals.size(); i++) {
            start = intervals[i][0];
            end = intervals[i][1];
            
            if(st.empty() && en.empty()) {
                st.push(start);
                en.push(end);
            } else {
                if(start <= en.top() && end > en.top()) {
                    en.pop();
                    en.push(end);
                }else if(start > en.top()) {
                    ans.push_back({st.top(), en.top()});
                    st.pop();
                    en.pop();
                    
                    st.push(start);
                    en.push(end);
                }
                
            }
         }
         
         if(!st.empty()) {
            ans.push_back({st.top(), en.top()});
         }
         
         
         
         return ans;
    }
};