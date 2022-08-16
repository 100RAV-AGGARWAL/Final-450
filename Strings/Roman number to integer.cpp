class Solution {
  public:
    unordered_map<char,int> roman = {
        {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}
    };
    
    int romanToDecimal(string &str) {
        // code here
        int n = str.length();
        int ans=roman[str[n-1]];
        
        for(int i=n-2; i>=0; i--) {
            if(roman[str[i]] < roman[str[i+1]]) {
                ans -= roman[str[i]];
            } else {
                ans += roman[str[i]];  
            }
        }
        
        return ans;
    }
};