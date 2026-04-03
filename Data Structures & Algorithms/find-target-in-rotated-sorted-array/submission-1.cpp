class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1, mid = 0, d = 0; //d is deflection point

        while(l < r)
        {
            if(nums[l] < nums[r])
            {
                d = l;
                break;
            }
            mid = (l + r) / 2;

            if(nums[mid] > nums[r]) l = mid + 1;
            else if(nums[mid] < nums[r]) r = mid;
            else;
        }
        d = l;  //after loop ends, l = r. That's where the deflection point is.

        int l1 = 0, r1 = d-1, mid1 = 0, l2 = d, r2 = n-1, mid2 = 0;
        while(l1 <= r1 or l2 <= r2)
        {
            mid1 = (l1 + r1) / 2;
            mid2 = (l2 + r2) / 2;

            if(nums[mid1] == target or nums[mid2] == target) break;
            else if(nums[mid1] > target) r1 = mid1 - 1;
            else l1 = mid1 + 1;

            if(nums[mid2] > target) r2 = mid2 - 1;
            else l2 = mid2 + 1;
        }
        if(nums[mid1] == target) d = mid1; //d is acting like res now
        else if(nums[mid2] == target) d = mid2;
        else d = -1;
        
        return d;
    }
};
