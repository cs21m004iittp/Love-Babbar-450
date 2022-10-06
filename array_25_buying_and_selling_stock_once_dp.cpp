//Question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*The task is to find the maximum profit after selling the stock once.
  We take two variables - buying_price (to keep track of the lowest buying price)
  and profit_after_selling (to keep track of the maximum profit attained).
  Every day, we make two sets of decisions - 
  1. buying decision: Whether to buy or to skip that day
  2. selling decision: Whether to sell or skip that day
  At the end of the last day, profit_after_selling will contain the maximum profit possible.
*/

//Time complexity: O(n) (traversing the array once)
//Auxiliary space used: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buying_price = INT_MAX, profit_after_selling = 0;
        
        for (int i = 0; i < n; i++)
        {
            buying_price = min(buying_price, prices[i]);      //buying_price taken as minimum of skipping or buying
            profit_after_selling = max(profit_after_selling, prices[i] - buying_price);   //profit_after_selling is taken as maximum of skipping or selling
        }
        
        return profit_after_selling;
    }
};
