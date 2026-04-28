class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int max_pre = 0; //it is max_suff too
        vector<int> pre(n, 0), suff(n, 0);

        for(int i = 0; i < n; i++)
        {
            max_pre = max(max_pre, height[i]);
            pre[i] = max_pre;
        }
        max_pre = 0;
        for(int i = n-1; i >= 0; i--)
        {
            max_pre = max(max_pre, height[i]);
            suff[i] = max_pre;
        }
        for(int i = 0; i < n; i++)
        {
            water += min(pre[i], suff[i]) - height[i];
        }

        return water;
    }
};