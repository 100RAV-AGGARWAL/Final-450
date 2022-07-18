class Solution {
public:
    bool binarySearch(vector<int> arr, int target, int size) {
        int start = 0, end = size-1;
        
        while(start <= end) {
            int mid = (start+end)/2;
            
            if(arr[mid] == target)
                return true;
            else if(arr[mid] < target) 
                start = mid+1;
            else
                end = mid-1;
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        if(target == matrix[0][0] || target == matrix[0][n-1])
            return true;
        else if(target > matrix[0][0] && target < matrix[0][n-1]) {
            return binarySearch(matrix[0], target, n);
        }
        
        for(int i=1; i<m; i++) {
            if(target == matrix[i][0] || target == matrix[i][n-1])
                return true;
            else if(target > matrix[i][0] && target < matrix[i][n-1]) {
                return binarySearch(matrix[i], target, n);
            } else if(target < matrix[i][0] && target > matrix[i-1][n-1])
                return false;
        }
        
        return false;
    }
};