class Solution {
public:
    vector<string> ans;
    set<string> Set;
    
    int countInvalid(string s) {
        if(s.length() == 0) return 0;
        
        stack<char> st;
        
        for(auto i : s) {
            if(i == '(') st.push(i);
            else if(i == ')') {
                if(i == ')' && (st.empty() || st.top() == ')')) {
                    st.push(i);
                } else {
                    st.pop();
                }
            }
        }
        
        return st.size();
    }
    
    void util(int invalid, string s) {
        if(invalid < 0) return;
        if(invalid == 0) {
            int cnt = countInvalid(s);
            if(cnt == 0) {
                ans.push_back(s);
            }
            return;
        }
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] != '(' && s[i] != ')') continue;
            
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            string str = left+right;
            if(Set.find(str) == Set.end()) {
                Set.insert(str);
                util(invalid-1, str);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int invalid = countInvalid(s);
        util(invalid, s);
        
        return ans;
    }
};