class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = *max_element(weights.begin(), weights.end());     //start of search range
        long long high = accumulate(weights.begin(), weights.end(), 0);  //end of search range. (shipping everything in one day)
        int n = weights.size();
        if(n == days) return low;

        long long mid, res;

        while(low <= high)
        {
            mid = (low + high) / 2; //capacity that'll be tested

            int sum = 0, count = 1, i = 0;
            while(i < n)
            {
                if(sum + weights[i] <= mid)
                {
                    sum += weights[i];
                    i++;
                }
                else
                {
                    count++; //count number of days
                    sum = 0; //reset total package weight
                }
            }

            if(count <= days)
            {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};