class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1); //because that's how many windows we'll get when applying SWP.
        deque<int> q;
        int i = 0, j = 0;

        while(j < n)
        {
            while(!q.empty() and nums[q.back()] < nums[j]) q.pop_back();

            q.push_back(j);

            if(i > q.front()) q.pop_front();

            if((j+1) >= k)
            {
                res[i] = nums[q.front()];
                i++;
            }
            j++;
        }
        return res;
    }
};
