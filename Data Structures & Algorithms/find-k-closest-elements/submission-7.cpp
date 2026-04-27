class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k >= arr.size()) return arr;

        int n = arr.size();
        int i = 0;
        while(i < n and arr[i] < x) i++;

        int l = i-1;
        int r = i;
        vector<int> res;


        while(k > 0)
        {
            if(l < 0)
            {
                res.push_back(arr[r++]);
            }
            else if(r >= n)
            {
                res.push_back(arr[l--]);
            }
            else if(abs(arr[l] - x) < abs(arr[r] - x))
            {
                res.push_back(arr[l--]);
            }
            else if(abs(arr[l] - x) == abs(arr[r] - x))
            {
                //if(arr[l] < arr[r]) 
                res.push_back(arr[l--]);
            }
            else
            {
                res.push_back(arr[r++]);
            }
            k--;       
        }
        sort(res.begin(), res.end());
        return res;

    }
};