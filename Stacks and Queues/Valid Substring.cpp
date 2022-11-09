class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int len = 0;
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                
                if(st.empty()) {
                    st.push(i);
                } else {
                    len = max(len, i-st.top());
                }
            }
        }
        
        return len;
    }
};