class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int start, int end) {        
        while(start <= end) {
            int mid = (end+start)/2;
            
            if(nums[mid] == target) {
                return mid;
            }
            
            if(nums[mid] > target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        
        return -1;
    }
    
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
    
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int n = nums.size();

        if(target == nums[pivot]) {
            return pivot;
        } else if(target > nums[pivot] && target <= nums[n-1]) {
            return binarySearch(nums, target, pivot+1, n-1);
        } else {
            return binarySearch(nums, target, 0, pivot-1);
        }
        
        return -1;
    }
};