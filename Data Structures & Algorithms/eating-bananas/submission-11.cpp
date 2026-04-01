class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long m = *max_element(piles.begin(), piles.end());
        if(piles.size() == h) return m;

        long long low = 1, high = m, mid, res = INT_MAX;
        
        while(low <= high)
        {
            mid = (low + high) / 2;
            long long sum = 0;

            for(int i = 0; i < piles.size(); i++)
            {
                sum += (piles[i] + mid - 1) / mid;
            }

            if(sum <= h)
            {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return res;
    }
};
