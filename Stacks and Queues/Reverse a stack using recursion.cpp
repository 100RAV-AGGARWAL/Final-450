class Solution{
public:
    void util(stack<int> &s, stack<int> &rev) {
        if(s.empty()) {
            return;
        }
        
        int ans = s.top();
        s.pop();
        rev.push(ans);
        
        util(s, rev);
    }
    
    void Reverse(stack<int> &St){
        if(St.empty()) {
            return;
        }
        
        stack<int> rev;
        
        util(St, rev);
        
        St = rev;
        
    }
};