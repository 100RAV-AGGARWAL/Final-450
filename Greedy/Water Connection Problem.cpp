class Solution
{
    public:
    static bool comp(vector<int> a, vector<int> b) {
        return a[2] < b[2];    
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> v(n+1);
        vector<int> deg(n+1, 0);
        
        for(int i=0; i<p; i++) {
            v[a[i]] = {b[i], d[i]};
            deg[b[i]]++;
        }
        
        for(int i=1; i<=n; i++) {
            if(deg[i] == 0 && v[i].size()>0) {
                int minD = v[i][1];
                int lastNode = v[i][0];
                
                while(v[lastNode].size() > 0 && lastNode != i) {
                    minD = min(minD, v[lastNode][1]);
                    lastNode = v[lastNode][0];
                }
                
                if(lastNode != i) ans.push_back({i, lastNode, minD});
                
            }
        }
        
        return ans;
    }
};