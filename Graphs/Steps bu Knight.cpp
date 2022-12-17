class Solution 
{
    public:
    bool isSafe(int N, int x, int y) {
        if(x >= 1 && y >= 1 && x <= N && y <= N) {
            return true;
        } else {
            return false;
        }
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<int> X{1, 2, 1, 2, -1, -2, -1, -2};
	    vector<int> Y{2, 1, -2, -1, 2, 1, -2, -1};
	    
	    int dp[N+1][N+1];
	    memset(dp, -1, sizeof dp);
	    
	    queue<pair<int, int>> q;
	    q.push({KnightPos[0], KnightPos[1]});
	    dp[KnightPos[0]][KnightPos[1]] = 0;
	    
	    while(!q.empty()) {
	        auto front = q.front();
	        q.pop();
	        
	        int x = front.first, y = front.second;
	        
	        if(x == TargetPos[0] && y == TargetPos[1])
                return dp[TargetPos[0]][TargetPos[1]];
	        
	        for(int i=0; i<8; i++) {
	            int nx = x + X[i];
	            int ny = y + Y[i];
	            
	            if(isSafe(N, nx, ny) && dp[nx][ny] == -1) {
	                dp[nx][ny] = 1 + dp[x][y];
	                q.push({nx, ny});
	            }
	        }
	    }
	    
	    return dp[TargetPos[0]][TargetPos[1]];
	}
};