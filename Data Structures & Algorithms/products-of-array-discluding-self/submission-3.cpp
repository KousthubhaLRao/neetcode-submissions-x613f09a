class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        vector<int> suf(nums.size(), 1);
        vector<int> res(nums.size(), 1);

        int prod = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            prod *= nums[i-1];
            pre[i] = prod;
        }

        prod = 1;
        for(int i = nums.size()-2; i >= 0; i--)
        {
            prod *= nums[i+1];
            suf[i] = prod;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            res[i] = pre[i]*suf[i];
        }
        return res;
    }
};


//This is better |
//               V

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res(n, 1);

//         for (int i = 1; i < n; i++) {
//             res[i] = res[i - 1] * nums[i - 1];
//         }

//         int postfix = 1;
//         for (int i = n - 1; i >= 0; i--) {
//             res[i] *= postfix;
//             postfix *= nums[i];
//         }
//         return res;
//     }
// };
