class Solution{
public:
    static bool isSafe(vector<vector<int>> board, int r, int i, int n) {
        if(r > 0 && i > 0) {
            int row = r-1, col = i-1;
            while(row >= 0 && col >= 0) {
                if(board[row][col] == 1) {
                    return false;
                }
                row--; col--;
            }
        }
        
        if(r > 0 && i < n-1) {
            int row = r-1, col = i+1;
            while(row >= 0 && col <= n-1) {
                if(board[row][col] == 1) {
                    return false;
                }
                row--; col++;
            }
        }
        
        if(r > 0) {
            int row = r-1, col = i;
            while(row >= 0) {
                if(board[row][col] == 1) {
                    return false;
                }
                row--;
            }
        }
        
        if(i > 0) {
            int row = r, col = i-1;
            while(col >= 0) {
                if(board[row][col] == 1) {
                    return false;
                }
                col--;
            }
        }
        
        if(i < n-1) {
            int row = r, col = i+1;
            while(col <= n-1) {
                if(board[row][col] == 1) {
                    return false;
                }
                col++;
            }
        }
        
        return true;
    }
    static void nQueenUtil(vector<vector<int>> &board, int r, int n, vector<vector<int>> &ans, vector<int> v) {
        if(r == n) {
            ans.push_back(v);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            if(isSafe(board, r, col, n)) {
                board[r][col] = 1;
                v.push_back(col+1);
                nQueenUtil(board, r+1, n, ans, v);
                v.pop_back();
                board[r][col] = 0;
            }
        }

    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        
        nQueenUtil(board, 0, n, ans, {});
        sort(ans.begin(), ans.end());
        return ans;
    }
};