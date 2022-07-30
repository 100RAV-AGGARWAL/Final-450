class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        
        for(auto i : x) {
            if(i == '(' || i == '{' || i == '[') {
                st.push(i);
            } else {
                if(st.empty())
                    return false;
                    
                char top = st.top();
                st.pop();
                
                if(i == ')' && top == '(') continue;
                else if(i == ']' && top == '[') continue;
                else if(i == '}' && top == '{') continue;
                else {
                    return false;
                }
            }
        }
        
        if(st.empty())
            return true;
        
        return false;
    }
};