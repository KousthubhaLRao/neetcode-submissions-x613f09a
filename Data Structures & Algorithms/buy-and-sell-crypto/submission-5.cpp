class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int low = prices[0], minIdx = 0;
        //int high = prices[n-1], maxIdx = 0;
        int profit = 0;

        for(int i = 1; i < n; i++)
        {
            low = min(low, prices[i]);
            profit = max(profit, prices[i]-low);
        }
        
       // profit = high - low;
        if(profit > 0) return profit;
        else return 0;
    }
};
