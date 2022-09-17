class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int foodReq = M*S;
        if(M > N) return -1;
        
        if(S>=7 && 7*M > 6*N) return -1;
        
        return foodReq%N == 0 ? foodReq/N : (foodReq/N)+1;
    }
};