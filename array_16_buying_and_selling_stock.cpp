//Question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*The task is to find the maximum profit that can be obtained by buying and selling the stock once.
  The idea is to buy the stock at a low price and sell the stock when prices are high.
  If the buy price is greater than sell price, we simply update the buy price as the sell price and
  increment the sell pointer. If we have steadily increasing values, we just update the sell pointer
  and update the profit with the maximum sell value, before moving on.
*/

//Time complexity: O(n) (traversing through the array once)
//Auxiliary space used: O(1) 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int buy = 0, sell = 1;
        
        while (buy < n && sell < n)
        {
            if (prices[buy] > prices[sell])         //If buy price is greater than sell price, just update the values
                buy = sell;
            else
            {
                while(sell+1 < n && prices[sell] < prices[sell+1])      //While prices are steadily increasing, increment the sell pointer
                    sell++; 
                
                max_profit = max(max_profit, prices[sell] - prices[buy]);       //Record the maximum profit
            }
            
            sell++;
        }
        
        return max_profit;
    }
};
