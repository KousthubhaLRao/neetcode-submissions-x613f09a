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

            if(i > q.front()) q.pop_front(); //"the index at the front of the deque is outside the current window"
                                            //Happens when there's a pretty big element in the beginning of the vector
                                            //such that no other element is bigger than it. But we still have to get rid
                                            //of it because it's now outta the window
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
