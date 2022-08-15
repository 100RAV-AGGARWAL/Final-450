int countRev (string s)
{
    // your code here
    if(s.length() % 2 != 0)
        return -1;
        
    stack<char> st;
    int rev=0;
    
    for(auto i : s) {
        if(i == '{') {
            st.push(i);
        } else {
            if(st.empty()) {
                rev++;
                st.push('{');
            } else {
                st.pop();
            }
        }
    }
    
    rev += st.size()/2;
    
    return rev;
    
}