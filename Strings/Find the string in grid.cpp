class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    
    bool helper(vector<vector<char>> &grid, string &word, int x, int y, int len, vector<int> &dir) {
        if(len == word.length()) {
            return true;
        }
        
        if( x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != word[len]) {
            return false;
        }
        
        return helper(grid, word, x+dir[0], y+dir[1], len+1, dir);
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    for(int i=0; i<grid.size(); i++) {
	        for(int j=0; j<grid[0].size(); j++) {
	            if(grid[i][j] == word[0]) {
    	            for(auto &d : dir) {
    	                if(helper(grid, word, i, j, 0, d)) {
    	                    ans.push_back({i, j});
    	                    break;
    	                }
    	            }
	            }
	        }
	    }
	    return ans;
	}
};