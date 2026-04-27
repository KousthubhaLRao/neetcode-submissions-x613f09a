class Solution {
public:
    void sortColors(vector<int>& nums) {
        qsort(nums, 0, nums.size()-1);
        //return nums;
    }

    void qsort(vector<int>&nums, int low, int high)
    {
        if(low >= high) return;

        int pivot = partition(nums, low, high);
        qsort(nums, low, pivot);
        qsort(nums, pivot+1, high);
    }
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        int i = low, j = high;

        while (true)
        {
            while (nums[i] < pivot) i++;
            while (nums[j] > pivot) j--;

            if (i >= j) return j;

            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};