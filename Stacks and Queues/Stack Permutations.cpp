class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> st;
        int i=0, j=0;
        
        while(i<N) {
            st.push(A[i++]);
            
            while(!st.empty() && st.top() == B[j]) {
                st.pop();
                j++;
            }
        }
        
        if(st.empty()) return 1;
        
        return 0;
    }
};