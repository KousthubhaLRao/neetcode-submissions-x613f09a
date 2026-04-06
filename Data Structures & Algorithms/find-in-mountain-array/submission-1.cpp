/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    unordered_map<int, int> cache;
    int get(int index, MountainArray &mountainArr)
    {
        if(!cache.count(index)) cache[index] = mountainArr.get(index);
        return cache[index];
    }
    int binarySearch(int l, int r, bool ascending, int target, MountainArray &mountainArr)
    {
        while(l <= r)
        {
            int m = (l + r) / 2;
            int val = get(m, mountainArr);
            if(val == target) return m;
            if(ascending == (val < target)) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        //find peak
        int l = 1, r = n - 2, peak = 0;
        while(l <= r)
        {
            int m = (l + r) / 2;
            int left = get(m-1, mountainArr);
            int mid = get(m, mountainArr);
            int right = get(m+1, mountainArr);
            if(left < mid and mid < right) l = m+1;
            else if(left > mid and mid > right) r = m - 1;
            else
            {
                peak = m;
                break;
            }
        }
        
        //search left portion
        int res = binarySearch(0, peak, true, target, mountainArr);
        if(res != -1) return res;

        //search right portion
        return binarySearch(peak, n-1, false, target, mountainArr);
    }
};