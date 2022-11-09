class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> left(n), right(n);
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, arr[i]*(right[i]-left[i]-1));
        }
        
        return ans; 
    }
};