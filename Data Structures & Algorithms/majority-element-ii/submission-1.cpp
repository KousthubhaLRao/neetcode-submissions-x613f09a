class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        vector<int> res;
        int n = nums.size();

        for(int x : nums)
        {
            if(hash.count(x)) hash[x]++;

            hash.insert({x,1}); 
        }

        for(pair x : hash)
        {
            if(x.second > (n/3)) res.push_back(x.first);
        }

        return res;
    }
};