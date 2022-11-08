class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        int ans = 0;
        
        for(auto ch : S) {
            if(ch >= '0' && ch <= '9') {
                st.push(ch - '0');
            } else {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                if(ch == '+') {
                    st.push(op1+op2);
                } else if(ch == '-') {
                    st.push(op2-op1);
                } else if(ch == '*') {
                    st.push(op1*op2);
                } else {
                    st.push(op2/op1);
                }
            }
        }
        
        return st.top();
    }
};