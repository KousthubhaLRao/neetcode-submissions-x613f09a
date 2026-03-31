class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x, mid, sqr, res;

        while(low <= high)
        {
            mid = (low + high) / 2;
            sqr = mid*mid;

            if(sqr == x) return mid;
            else if(sqr > x) high = mid-1;
            else
            {
                res = mid;
                low = mid+1;
            }
        }
        return res;
    }
};