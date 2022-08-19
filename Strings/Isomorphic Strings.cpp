class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        unordered_map<char, int> m1, m2;
        
        for(auto i : str1) {
            m1[i]++;
        }
        for(auto i : str2) {
            m2[i]++;
        }
        
        if(m1.size() != m2.size()) return false;
        
        for(int i=0; i<str1.length(); i++) {
            if(m1[str1[i]] != m2[str2[i]]) return false;
            else {
                m1[str1[i]]--;
                m2[str2[i]]--;
            }
        } 
        return true;
    }
};