class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int n = arr.size();
        int l = 0, r = n-k; //r is the rightmost valid starting index

        while(l < r)
        {
            int m = (l + r) / 2;

            if((x-arr[m]) > (arr[m+k] - x)) l = m+1;
            else r = m;
        }
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};