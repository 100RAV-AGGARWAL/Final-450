int findPivot(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1 || nums[0] < nums[n-1]) {
            return 0;
        }
        
        int start=0, end=n-1;
        
        while(start <= end) {
            int mid = (end+start)/2;
            
            if(mid > 0 && nums[mid] < nums[mid-1]) {
                return mid;
            }
            
            if(nums[mid] < nums[0]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        
        return 0;
    }