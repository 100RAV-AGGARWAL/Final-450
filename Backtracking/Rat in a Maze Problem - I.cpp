class Solution{
    public:
    static void findPathUtil(vector<vector<int>> &m, int r, int c, int n, vector<string> &paths, string curr) {
        if(r == n-1 && c == n-1) {
            if(m[r][c] == 1)
                paths.push_back(curr);
                
            return;
        }
        
        if(m[r][c] == 0) return;
        
        m[r][c] = 0;
        
        //right
        if(c < n-1) {
            findPathUtil(m, r, c+1, n, paths, curr + "R");
        }
        
        //left
        if(c > 0) {
            findPathUtil(m, r, c-1, n, paths, curr + "L");
        }
        
        //up
        if(r > 0) {
            findPathUtil(m, r-1, c, n, paths, curr + "U");
        }
        
        //down
        if(r < n-1) {
            findPathUtil(m, r+1, c, n, paths, curr + "D");
        }
        
        m[r][c] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> paths;
        
        findPathUtil(m, 0, 0, n, paths, "");
        
        return paths;
    }
};