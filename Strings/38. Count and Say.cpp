class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        else if(n == 2)
            return "11";
        
        string smallAns = countAndSay(n-1);
        
        string ans="";
        int count=1, i;
        for(i=1; i<smallAns.length(); i++) {
            if(smallAns[i] == smallAns[i-1])
                count++;
            else {
                ans = ans + to_string(count) + smallAns[i-1];
                count=1;
            }
        }
        
        ans = ans + to_string(count) + smallAns[i-1];
        
        return ans;
    }
};