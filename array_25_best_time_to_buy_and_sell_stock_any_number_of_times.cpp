//Question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*The task is to find the maximum profit that can be earned by buying and selling stock any number of times.
  The only constraint is that a stock cannot be bought without the previous one being sold first.
  
  The buy and sell counters are increased by 1 untill we find a condition where buy prices is less than sell prices.
  Once this condition is fullfilled, we iterate through the array to find the highest sell price (i.e. we iterate
  through the array untill the immediate right element of sell is no longer greater than sell). Once the maximum selling price 
  is found out, the profit is added to the total profit. Then buy is initialised to just after sell and sell to the next of new buy.
  The process repeats itself untill the end of the array is reached.
*/

//Time complexity: O(n) (traversing the array once)
//Auxiliary space used: O(1) 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0, sell = 1;
        int total_profit = 0;
        
        while (buy < n && sell < n)
        {
            if (prices[sell] < prices[buy])   //Untill we find a condition where buy price is less than sell price, the buy and sell pointers are updated
            {
                buy = sell;
                sell++;
            }
            else                            //Once we find a condition where sell price is greater than buy price
            {
                while (sell+1 < n && prices[sell+1] > prices[sell])   //Untill the prices keep monotonically increasing, we increment the sell pointer
                    sell++;
                
                total_profit += (prices[sell] - prices[buy]);       //The profit is added to the total profit 
                
                buy = sell+1;         //Buy and sell pointers are updated
                sell = buy+1;
            }
        }
        
        return total_profit;
    }
};
