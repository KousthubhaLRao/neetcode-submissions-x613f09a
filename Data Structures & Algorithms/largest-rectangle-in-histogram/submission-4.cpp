class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stak;
        int n = heights.size();
        int max_area = 0;

        for(int i = 0; i <= n; i++)
        {
            while(!stak.empty() and (i == n or heights[i] <= heights[stak.top()]))
            {
                int h = heights[stak.top()]; stak.pop();

                int width = 0;
                if(stak.empty()) width = i; //from 0 to i-1
                else width = i - stak.top() - 1;

                max_area = max(max_area, h * width);
            }
            stak.push(i);
        }
        return max_area;
    }
};
