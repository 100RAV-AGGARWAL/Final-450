class Solution{
public:
    string chooseandswap(string s){
        // Code Here
        string str = s;
        int n = s.length();
        sort(str.begin(), str.end());
        
        map<char, int> m;
        
        char a, b;
        int j=0;
        
        for(int i=0; i<n-1; i++) {
            if(s[i] != str[j] && m[s[i]] == 0) {
                a = s[i];
                b = str[j];
                break;
            } else if(s[i] == str[j]) {
                m[s[i]] = 1;
                while(str[j] == str[j+1] && j<n-1) j++;
                j++;
            }
        }
        
        for(int i=0; i<n; i++) {
            if(s[i] == a) s[i] = b;
            else if(s[i] == b) s[i] = a;
        }
        
        return s;
    }
    
};