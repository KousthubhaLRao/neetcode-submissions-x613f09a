class Solution { //i kinda understand it, but still need to revisit.
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int min = *max_element(nums.begin(), nums.end());
        int max = accumulate(nums.begin(), nums.end(), 0);
        if(k == n-1 or k == n) return min;
        if(k == 1) return max;

        int i = 0, mid, res;
        while(min <= max)
        {
            mid = (min + max) / 2;
            int sum = 0, count = 1; //count of subarrays formed
            for(int x : nums)
            {
                if(sum + x > mid)
                {
                    count++;
                    sum = x;
                }
                else sum += x;
            }
            if(count <= k)
            {
                res = mid;
                max = mid - 1;
            }
            else min = mid + 1;
        }
        return res;
    }
};