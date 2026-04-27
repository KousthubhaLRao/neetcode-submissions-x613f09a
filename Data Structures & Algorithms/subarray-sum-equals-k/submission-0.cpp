class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pre;
        pre[0] = 1; //The hashmap stores: "How many times we've seen each prefix sum so far."
        //prefix sum = 0 means that the subarray starts from the first element

        int sum = 0, res = 0, diff;
        for(int x : nums)
        {
            sum += x;
            diff = sum - k;
            res += pre[diff];
            pre[sum]++;
        }

        //hmm, we need to count the number of times the difference between any two prefix sums is equal to k.
        //But, we can't use standard indexing to check differences and verify.
        // we want k = pre[j] - pre[i]
        // or pre[i] = pre[j] - k
        // so we calculate the difference, and count the occurrence of that difference using the hashmap.
        
        return res;
    }
};