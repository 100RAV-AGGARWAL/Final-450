class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s1;
        
        for(auto i : x) {
            if(i == '(' || i == '[' || i == '{') {
                s1.push(i);
            } else {
                if(s1.empty()) return false;
                
                char ch = s1.top();
                s1.pop();
                
                if((i == ')' && ch == '(') || (i == ']' && ch == '[') || (i == '}' && ch == '{')) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        
        if(s1.empty()) return true;
        
        return false;
    }

};