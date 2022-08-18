class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int slen = s.length();
        int plen = p.length();
        
        if(plen > slen)
            return "-1";
        
        int pCharCnt = 0;
        int len = INT_MAX, start = 0;
        
        unordered_map<char, int> m;
        
        for(auto i : p) {
            if(m[i] == 0) {
                pCharCnt++;
            }
            m[i]++;
        }
        
        int i=0, j=0;
        while(j < slen) {
            m[s[j]]--;
            
            if(m[s[j]] == 0) pCharCnt--;
            
            if(pCharCnt == 0) {
                while(pCharCnt == 0) {
                    if(len > j-i+1) {
                        len = min(len, j-i+1);
                        start = i;
                    }
                    
                    m[s[i]]++;
                    
                    if(m[s[i]] > 0) pCharCnt++;
                    
                    i++;
                }
            }
            j++;
        }
        
        if(len != INT_MAX) return s.substr(start, len);
        
        return "-1";
    }
};