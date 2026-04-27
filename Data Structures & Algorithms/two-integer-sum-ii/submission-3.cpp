class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        int sum = 93857;
        
        while(sum != target)
        {
            sum = numbers[i] + numbers[j];
            if(sum < target) i++;
            else if(sum > target) j--;
            else break;
        }
        return {i+1, j+1};
    }
};
