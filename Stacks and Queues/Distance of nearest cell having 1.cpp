class Solution 
{
    public:
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool isSafe(int x, int y, int m, int n) {
        return x < m && y < n && x >= 0 && y >= 0;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m = grid.size();
	    int n = grid[0].size();
	    queue<pair<int, int>> q;
	    vector<vector<int>> ans(m, vector<int>(n, -1));
	    
	    for(int i=0; i<m; i++) {
	        for(int j=0; j<n; j++) {
	            if(grid[i][j] == 1) {
	                q.push({i, j});
	                ans[i][j] = 0;
	            }
	        }
	    }
	    
	    while(!q.empty()) {
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        
	        for(int i=0; i<4; i++) {
	            if(isSafe(x+moves[i][0], y+moves[i][1], m, n) && ans[x+moves[i][0]][y+moves[i][1]] == -1) {
	                ans[x+moves[i][0]][y+moves[i][1]] = ans[x][y]+1;
	                q.push({x+moves[i][0], y+moves[i][1]});
	            }
	        }
	    }
	    
	    return ans;
	}
};