class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        //unordered_set<vector<int>> s;
        sort(nums.begin(), nums.end());

        for(int k = 0; k < n; k++)
        {
            if(k > 0 and nums[k] == nums[k-1]) continue;

            int i = k+1;
            int j = n-1;
            while(i < j)
            {
                int sum = nums[i] + nums[j];
                if(sum < -nums[k]) i++;
                else if(sum > -nums[k]) j--;
                else
                {
                    res.push_back({nums[k], nums[i], nums[j]});
                    i++;
                    j--;
                    while(i<j and nums[i] == nums[i-1]) i++;
                    while(i<j and nums[j] == nums[j+1]) j--;   //we want to skip duplicates only when we find a valid triplet
                }
                
            }
        }
        return res;
    }
};
