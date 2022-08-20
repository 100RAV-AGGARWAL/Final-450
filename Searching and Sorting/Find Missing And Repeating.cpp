class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        vector<int> num(n+1, 0);
        int *ans = new int[2];
        
        for(int i=0; i<n; i++) {
            num[arr[i]]++;
        }
        
        for(int i=1; i<=n; i++) {
            if(num[i] == 2) ans[0] = i;
            if(num[i] == 0) ans[1] = i;
        }
        
        return ans;
    }
};