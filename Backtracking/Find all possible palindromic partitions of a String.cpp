class Solution {
  public:
    bool isPalindrome(string s, int low, int high) {
        
        while(low < high) {
            if(s[low] != s[high]) return false;
            
            low++; high--;
        }
        
        return true;
    }
    
    void util(string s, int n, vector<string> &curr, int start, vector<vector<string>> &ans) {
        if(start >= n) {
            ans.push_back(curr);
            return;
        }
        
        for(int i=start; i<n; i++) {
            if(isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i-start+1));
                util(s, n, curr, i+1, ans);
                curr.pop_back();
            }
        }
    }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        vector<string> curr;
        
        util(S, S.length(), curr, 0, ans);
        
        return ans;
    }
};