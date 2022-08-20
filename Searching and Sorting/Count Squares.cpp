class Solution {
  public:
    int countSquares(int N) {
        // code here
        int ans=0;
        
        for(int i=1; i<=N/2; i++) {
            if(i*i < N) {
                ans++;
            } else {
                break;
            }
        }
        
        return ans;
    }
};