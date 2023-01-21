class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<int> st;
        vector<int> ans(n, 1);
        st.push(0);
        
        for(int i=1; i<n; i++) {
            while(!st.empty() && price[st.top()] <= price[i]) {
                st.pop();
            }
            
            int t = st.empty() ? i+1 : i - st.top();
            ans[i] = t;
            st.push(i);
        }
        
        return ans;
       
    }
};