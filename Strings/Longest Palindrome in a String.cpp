class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int maxLen = 1, start=0, end=0;
        int n = S.length();
        
        for(int i=0; i<n; i++) {
            int l=i, r=i;
            
            while(l >= 0 && r < n) {
                if(S[l] == S[r]) {
                    l--;
                    r++;
                } else {
                    break;
                }
            }
            
            int len = r - l - 1;
            if(len > maxLen) {
                maxLen = len;
                start = l+1;
            }
        }
        
        for(int i=0; i<n; i++) {
            int l=i, r=i+1;
            
            while(l >= 0 && r < n) {
                if(S[l] == S[r]) {
                    l--;
                    r++;
                } else {
                    break;
                }
            }
            
            int len = r - l - 1;
            if(len > maxLen) {
                maxLen = len;
                start = l+1;
            }
        }
        return S.substr(start, maxLen);
    }
};