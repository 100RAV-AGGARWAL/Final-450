class Solution
{
    public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;    
    }
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++) {
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), comp);
        
        int ans = 1;
        int st = v[0].first, en = v[0].second;
        
        for(int i=1; i<n; i++) {
            if(v[i].first > en) {
                ans++;
                st = v[i].first;
                en = v[i].second;
            }
        }
        
        return ans;
    }
};