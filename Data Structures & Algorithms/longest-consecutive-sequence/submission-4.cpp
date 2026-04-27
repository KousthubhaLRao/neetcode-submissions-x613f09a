class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> arr(nums.begin(), nums.end());
        // //nums.clear();
        // int len = 0;
        // int longest = 0;
        // for(int x : arr)
        // {
        //     if(!arr.count(x-1))
        //     {
        //         len++;
        //         arr.erase(x);
        //     }
        //     if(len>=longest) longest = len;
        // }

        // return len;

        if(!nums.size()) return 0;
        sort(nums.begin(), nums.end());
        int res = 0, curr, streak = 0, i = 0;

        while(i < nums.size())
        {
            if(nums[i] != curr)
            {
                curr = nums[i];
                streak = 0;
            }
            while(nums[i] == curr) i++;
            streak++;
            curr++;
            if(streak >= res) res = streak;
        }
        return res;
    }
};
