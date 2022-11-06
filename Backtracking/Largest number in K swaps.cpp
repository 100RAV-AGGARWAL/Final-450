class Solution
{
    public:
    void util(string str, string &mx, int k, int ind) {
        if(k == 0) return;
        
        char maxNum = str[ind];
        for(int i=ind+1; i<str.length(); i++) {
            maxNum = max(maxNum, str[i]);
        }
        
        if(maxNum != str[ind]) k--;
        
        for(int i=str.length()-1; i>=ind; i--) {
            if(str[i] == maxNum) {
                swap(str[i], str[ind]);
                mx = max(mx, str);
                
                util(str, mx, k, ind+1);
                
                swap(str[i], str[ind]);
            }
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string mx = str;
       util(str, mx, k, 0);
       return mx;
    }
};