class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(auto x : nums)
        {
            int index = abs(x) - 1;
            if(nums[index] < 0) return abs(x);
            
            nums[index] *= -1;
        }
    }
};
