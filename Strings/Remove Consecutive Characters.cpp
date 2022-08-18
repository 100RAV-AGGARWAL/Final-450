class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string ans="";
        int ind=1;
        
        ans += S[0];
        
        while(ind < S.length()) {
            if(S[ind] == S[ind-1]) {
                ind++;
            } else {
                ans += S[ind];
                ind++;
            }
        }
        
        return ans;
    }
};