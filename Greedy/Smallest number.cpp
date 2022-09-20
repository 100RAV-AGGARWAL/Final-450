class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here
        if(S > D*9) return "-1";
        S--;
        
        int ans = (int)pow(10, D-1);
        int place=1;
        while(S > 0) {
            ans += place*min(S, 9);
            S -= min(S, 9);
            place *= 10;
        }
        
        return to_string(ans);
    }
};