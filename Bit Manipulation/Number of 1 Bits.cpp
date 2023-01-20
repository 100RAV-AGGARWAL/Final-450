class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int ans = 0;
        
        while(N > 0) {
            ans++;
            N = N & (N-1);
        }
        
        return ans;
    }
};