class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int i = 0, j = n-1;
        int maxi = height[i], maxj = height[j];

        if(n == 0) return 0;

        while(i < j)
        {
            if(maxi < maxj)
            {
                i++;
                maxi = max(maxi, height[i]);
                water += maxi - height[i];
            }
            else
            {
                j--;
                maxj = max(maxj, height[j]);
                water += maxj - height[j];
            }
        }
        return water;
    }
};