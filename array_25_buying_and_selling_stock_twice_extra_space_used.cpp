//Question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*The task is to find the maximum profit when buying and selling the stocks at most twice.
  The idea is to divide the array into two parts at every point and then check the maximum profit of
  buying and selling stocks in each half. Atlast the maximum profit is found out by adding up the 
  profits of the two halves.
  To move from left to right, we maintain an array of profits and a min_buy variable. At every point
  we find the max profit upto that point and update the variable min_buy if we find a lower value than
  the current one.
  To move from right to left, we maintain an array of profits and a max_sell variable. At every point
  we find the max profit upto that point and update the variable max_sell if we find a higher value
  than the current one.
  Lastly, we calculate the max_profit to be the maximum of (profit[i-1] in left to right array + 
  profit[i] in right to left array).
*/

//Time complexity: O(n) + O(n) = O(n) (traversing through the prices array twice)
//Auxiliary space used: O(n) + O(n) = O(n)  (one for left to right array and another for right to left array)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left_to_right(n);
        left_to_right[0] = 0;
        vector<int> right_to_left(n);
        right_to_left[n-1] = 0;
        int left_min = prices[0], right_max = prices[n-1];
        
        for (int i = 1; i < n; i++)         //traversing through the left to right array and finding the max profit upto that point
        {
            left_to_right[i] = max(left_to_right[i-1], prices[i] - left_min);
            left_min = min(left_min, prices[i]);
        }
    
        for (int i = n-2; i >= 0; i--)      //traversing trhough the right to left array and finding the max profit upto that point
        {
            right_to_left[i] = max(right_to_left[i+1], right_max - prices[i]);
            right_max = max(right_max, prices[i]);
        }
        
        int profit = right_to_left[0];
        for (int i = 1; i < n; i++)         //profit is maximum of max_profit upto previous point and left_to_right[i-1] + right_to_left[i] (i.e. this point)
            profit = max(profit, left_to_right[i-1] + right_to_left[i]);
        
        return profit;
    }
};
