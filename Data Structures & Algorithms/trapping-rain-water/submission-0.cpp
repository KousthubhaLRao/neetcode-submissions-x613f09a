class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        for(int k = 0; k < n; k++)
        {
            int maxi = 0, maxj = 0;

            // left max
            for(int i = k-1; i >= 0; i--)
                maxi = max(maxi, height[i]);

            // right max
            for(int j = k+1; j < n; j++)
                maxj = max(maxj, height[j]);

            int res = max(0, min(maxi, maxj) - height[k]);
            water += res;
        }

        return water;
    }
};