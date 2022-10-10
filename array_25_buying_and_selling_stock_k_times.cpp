//Question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

/* The task is to find the maximum profit obtained by performing at most k transactions.
   We take two arrays of length k, one for recording all buyings and the other for recording all sellings.
   We perform a buy if the current buying price is less than the previous buying price.
   We perform a sell if the current profit after selling is less than the profit to be gained.
   
   This is just the generalisation of the concept used in buying_and_selling_stock_twice.
*/

//Time complexity: O(n * k) (For every element in prices, we go through each buy and sell element)
//Auxiliary space used: O(k)  (Two arrays of length k for storing buy prices and profits after selling)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int i, j;
        
        int buy_prices[k];
        int profits_after_selling[k];
        for (i = 0; i < k; i++)
        {
            buy_prices[i] = INT_MIN;        //All buying prices initialised with INT_MIN to mean maximum loss after buying possible
            profits_after_selling[i] = 0;   //Since the investor is intelligent, he will not make any loss and his minimum profit can be 0.
        }
        
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < k; j++)
            {
                if (j == 0)
                    buy_prices[j] = max(buy_prices[j], -prices[i]);
                else
                    buy_prices[j] = max(buy_prices[j], profits_after_selling[j-1] - prices[i]);
                
                profits_after_selling[j] = max(profits_after_selling[j], prices[i] + buy_prices[j]);
            }
        }
        
        return profits_after_selling[k-1];
    }
};
