class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        if(C == 0) {
            if(A==B) return 1;
            else return 0;
        }
        
        float n = (B-A)/(C*1.00) + 1.00;
        int num = n;
        
        if(n != num || n <= 0) return 0;
        else return 1;
    }
};