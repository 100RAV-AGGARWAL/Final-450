class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        vector<int> curr;
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        
        util(ans, A, B, 0, curr);
        
        return ans;
    }
    
    void util(vector<vector<int>> &ans, vector<int> &A, int B, int ind, vector<int> &curr) {
        if(ind == A.size()) {
            if(B == 0) ans.push_back(curr);
            
            return;
        }
        
        if(A[ind] <= B) {
            curr.push_back(A[ind]);
            util(ans, A, B-A[ind], ind, curr);
            curr.pop_back();
        }
        
        util(ans, A, B, ind+1, curr);
    }
};