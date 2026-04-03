class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1, mid, res = INT_MAX;

        if(nums[l] <= nums[r]) return nums[l];
        //else it's been rotated.
        //and if it's been rotated, the left pointer can be made to go more and more to the right until 
        //we find a nums[l] that is smaller than nums[r]

        while(l <= r)
        {
            mid = (l + r) / 2;
            if(nums[mid] < nums[r])
            {
                res = min(nums[mid], res);
                r = mid;
            }
            else if(nums[mid] == nums[r])
            {
                return nums[mid];
            }
            else l = mid + 1;
            
        }

        return res;

    }
};
