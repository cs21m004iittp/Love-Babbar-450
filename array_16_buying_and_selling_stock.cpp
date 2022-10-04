//Question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit, max_profit = 0;
        int buy = 0, sell = 1;
        
        while (buy < n && sell < n)
        {
            if (prices[buy] > prices[sell])
                buy = sell;
            else
            {
                profit = prices[sell] - prices[buy];
                max_profit = max(max_profit, profit);
            }
            
            sell++;
        }
        
        return max_profit;
    }
};
