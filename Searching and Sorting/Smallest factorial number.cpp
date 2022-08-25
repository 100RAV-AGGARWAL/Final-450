class Solution
{
    public:
    static bool isValid(int mid, int n) {
        int zeros = 0;
        
        for(int i = 5; i <= mid; i *= 5) {
            zeros += mid/i;
        }
        
        if(zeros >= n) return true;
        else return false;
    }
    
    int findNum(int n) {
        //complete the function here
        int high = 1000000009;
        int low = 0;
        int ans = -1;
        
        while(low <= high) {
            int mid = (high+low)/2;
            
            if(isValid(mid, n)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};