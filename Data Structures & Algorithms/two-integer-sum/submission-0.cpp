class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> n;
        int len = nums.size();
        int d;
        for(int i = 0; i<len; i++)
        {
            d = target-nums[i];
            if(n.find(d) != n.end()) return {n[d], i};

            n[nums[i]] = i;
        }
    }
};
