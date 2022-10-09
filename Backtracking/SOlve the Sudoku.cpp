class Solution 
{
    public:
    bool isSafe(int grid[N][N], int row, int col, int num) {
        for(int i=0; i<N; i++) {
            if(grid[i][col] == num) return false;
            if(grid[row][i] == num) return false;
            if(grid[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == num) return false;
        }
        
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j] == 0) {
                    for(int num = 1; num<=9; num++) {
                        if(isSafe(grid, i, j, num)) {
                            grid[i][j] = num;
                            if(SolveSudoku(grid)) return true;
                            else grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cout<< grid[i][j] << " ";
            }
        }

    }
};