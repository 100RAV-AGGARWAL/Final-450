class Solution{
  public:
        // Your code here
        int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans=MAH(M[0],m),c=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==1) M[i][j] += M[i-1][j];
                
            }
            ans= max(ans,MAH(M[i],m));
            
        }
        return ans;
    }
  
    int MAH(int M[],int m) {      
        stack<int> st;
          int rans=0,height,width;
          for(int j=0;j<=m;j++)
            {
                
                while(!st.empty() && (j==m || M[st.top()] >= M[j]))
                {
                    int height=  M[st.top()];
                    st.pop();
                    if(st.empty())width=j;
                    else width=j-st.top()-1;
                    
                    rans= max(rans,width*height);
                }
                st.push(j);
            }
             return rans;
    }
        
};