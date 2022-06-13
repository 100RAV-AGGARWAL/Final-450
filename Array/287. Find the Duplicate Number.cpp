class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        
        set<int> s;
        
        for(int i=0; i<size; i++) {
            if(s.find(nums[i]) != s.end())
                return nums[i];
            else
                s.insert(nums[i]);
        }
        
        return 0;
    }
};