class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for(int k = 0; k < n; k++)
        {
            if(k > 0 and nums[k] == nums[k-1]) continue;

            for(int l = k+1; l < n; l++)
            {
                if(l > k+1 and nums[l] == nums[l-1]) continue;

                int i = l+1;
                int j = n-1;

                while(i < j)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum < target) i++;
                    else if(sum > target) j--;

                    else
                    {
                        res.push_back({nums[k], nums[l], nums[i], nums[j]});
                        i++;
                        j--;

                        while(i<j and nums[i] == nums[i-1]) i++;
                        while(i<j and nums[j] == nums[j+1]) j--; 
                    }
                }
            }
        }
        return res;
    }
};