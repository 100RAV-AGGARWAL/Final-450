class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here   
        long long int prod = 1;
        vector<long long int> v(n, 0);
        int zeroCnt = 0;
        
        for(auto i: nums) {
            if(i == 0) zeroCnt++;
            else {
                prod *= i;
            }
            
            if(zeroCnt >= 2) return v;
        }
        
        for(int i=0; i<n; i++) {
            if(nums[i] != 0 && zeroCnt == 0) {
                v[i] = prod / nums[i];
            } else if(nums[i] == 0 && zeroCnt == 1) {
                v[i] = prod;
            }
        }
        
        return v;
    }
};