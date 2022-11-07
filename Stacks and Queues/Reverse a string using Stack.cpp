char* reverse(char *S, int len)
{
    //code here
    char* ans = new char[len];
    
    stack<char> s;
    
    for(int i=0; i<len; ++i) {
        s.push(S[i]);    
    }
    
    for(int i=0; i<len; ++i) {
        ans[i] = s.top();
        s.pop();
    }
    
    return ans;
}