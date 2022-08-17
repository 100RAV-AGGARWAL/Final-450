class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        set<char> s;
        for(auto i:str) {
            s.insert(i);
        }
        
        unordered_map<char, int> m;
        int i=0, j=0;
        int ans = str.length();
        
        while(i < str.length()) {
            m[str[i]]++;
            if(m.size() == s.size()) {
                while(m[str[j]] > 1) {
                    m[str[j]]--;
                    j++;
                }
                ans = min(ans, i-j+1);
            }
            i++;
        }
        
        return ans;
    }
};