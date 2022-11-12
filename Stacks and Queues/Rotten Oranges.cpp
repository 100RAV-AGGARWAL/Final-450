class Solution 
{
    public:
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool isSafe(vector<vector<int>>& grid, int x, int y) {
        return x < grid.size() && y < grid[0].size() && grid[x][y] == 1;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int minTime = 0;
        
        int m = grid[0].size();
        int n = grid.size();
        
        auto newgrid = grid;
        bool flag = false;
        
        do {
            flag = false;
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(grid[i][j] == 2) {
                        for(int k=0; k<4; k++) {
                            if(isSafe(grid, i+moves[k][0], j+moves[k][1])) {
                                newgrid[i+moves[k][0]][j+moves[k][1]] = 2;
                                flag = true;
                            }
                        }
                    }
                }
            }
            
            grid = newgrid;
            
            if(flag) minTime++;
        } while(flag);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return minTime;
    }
};