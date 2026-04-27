class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0;
        int n = nums.size(), min_len = INT_MAX;

        while(j < n)
        {
            sum += nums[j++];

            while(sum >= target)
            {
                min_len = min(min_len, j-i);
                sum -= nums[i++];
            }
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};