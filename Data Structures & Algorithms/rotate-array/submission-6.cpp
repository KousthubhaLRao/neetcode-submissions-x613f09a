class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        // //reverse() syntax:
        // reverse(start_iterator, end_iterator);
        // What do these mean?
        // start_iterator → where to start reversing (inclusive)
        // end_iterator → where to stop (exclusive ❗)
        // 👉 It reverses elements in the range:
        // [start, end)
    }
};