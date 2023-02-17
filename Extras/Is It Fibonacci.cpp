class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        if(K >= N) return GeekNum[N-1];
        
        long long sum = 0;
        vector<long long> pf = GeekNum;
        for(auto i : GeekNum) {
            sum += i;
        }
        
        pf.push_back(sum);
        for(long long i=K+1; i<=N; i++) {
            sum += pf[i-1];
            sum -= pf[i-K-1];
            pf.push_back(sum);
        }
        
        return pf[N-1];

        
    }
};