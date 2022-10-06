//Question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*The task is to buy and sell the stock atmost twice in order to maximise the profit.
  We take four variables - buy_once_price (price of buying for the first time),
  profit_after_selling1 (profit after selling the stock once), 
  profit_after_buying2 (profit leftover after buying the stock for the second time),
  profit_after_selling2 (profit after selling the stock for the second time).
  The idea here is to maximise the profit at each point.
*/

//Time complexity: O(n) (traversing the array once)
//Auxiliary space used: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_once_price = INT_MAX;
        int profit_after_selling1 = 0;
        int profit_after_buying2 = INT_MIN;
        int profit_after_selling2 = 0;
        
        for (int i = 0; i < n; i++)
        {
            buy_once_price = min(buy_once_price, prices[i]);
            profit_after_selling1 = max(profit_after_selling1, prices[i] - buy_once_price);
            profit_after_buying2 = max(profit_after_buying2, profit_after_selling1 - prices[i]);
            profit_after_selling2 = max(profit_after_selling2, prices[i] + profit_after_buying2);
        }
        
        return profit_after_selling2;
    }
};
