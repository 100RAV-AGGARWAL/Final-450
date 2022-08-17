class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        unordered_map<char, int>m;
        int maxCnt = 0;
        int n = str.length();
        
        for(auto i : str) {
            m[i]++;
            maxCnt = max(maxCnt, m[i]);
        }
        
        if(maxCnt > (n+1)/2)
            return "-1";
            
        char maxChar;
        for(auto itr : m) {
            if(itr.second == maxCnt) {
                maxChar = itr.first;
                break;
            }
        }
        
        int start = 0;
        while(m[maxChar]--) {
            str[start] = maxChar;
            start += 2;
            if(start >= n) start=1;
        }
        
        m[maxChar] = 0;
        
        for(auto itr:m) {
            while(itr.second--) {
                str[start] = itr.first;
                start+=2;
                if(start>=n) start = 1;
            }
        }
        
        return str;
    }
    
};
