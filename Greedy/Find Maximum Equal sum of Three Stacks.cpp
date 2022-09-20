class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int s1=0, s2=0, s3=0;
        
        for(auto i : S1) s1 += i;
        for(auto i : S2) s2 += i;
        for(auto i : S3) s3 += i;
        
        int t1 = 0, t2 = 0, t3 = 0;
        while(true) {
            if(t1 == N1 || t2 == N2 || t3 == N3) return 0;
            
            if(s1 == s2 && s2 == s3) return s1;
            
            if(s1 >= max(s2, s3)) s1 -= S1[t1++];
            else if(s2 >= max(s1, s3)) s2 -= S2[t2++];
            else if(s3 >= max(s1, s2)) s3 -= S3[t3++];
        }
        
        return 0;
    }
};