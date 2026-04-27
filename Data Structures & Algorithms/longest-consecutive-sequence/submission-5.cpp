class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> arr(nums.begin(), nums.end());
        int len;
        int longest = 0;
        for(int x : arr)
        {
            if(!arr.count(x-1))
            {
                len = 1;
                while(arr.count(x+len)) len++;
                if(len>=longest) longest = len;
            }
            
        }

        return longest;


        //SORTING SOLUTION
        // if(!nums.size()) return 0;
        // sort(nums.begin(), nums.end());
        // int res = 0, curr, streak = 0, i = 0;

        // while(i < nums.size())
        // {
        //     if(nums[i] != curr)
        //     {
        //         curr = nums[i];
        //         streak = 0;
        //     }
        //     while(nums[i] == curr) i++;
        //     streak++;
        //     curr++;
        //     if(streak >= res) res = streak;
        // }
        // return res;
    }
};
