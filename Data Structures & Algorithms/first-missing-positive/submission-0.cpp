class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int missing = 1;
        for(auto x : nums)
        {
            if(x <= 0) continue;
            
            if(missing == x) missing++;
        }
        return missing;
    }
};