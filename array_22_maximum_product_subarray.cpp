//Question link: https://leetcode.com/problems/maximum-product-subarray/

/*Multiplication of two negative numbers result in a positive number. So, we maintain two variables here. 
  One is curr_max, the other is curr_min. 
  In case the current element is positive, then multiplying with curr_max will result in a greater number.
  One the other hand if the current element is negative, then multiplying it with curr_min will result in a greater number.
  For example, at any point in time, curr_max = 3, and curr_min = 2. 
  Case1: curr_element = 6 (positive), then curr_max * curr_element = 3 * 6 = 18 (which is greater than 2 * 6 = 12).
  Case2: curr_element = -6 (negative), then curr_min * curr_element = 2 * (-6) = -12 (which is greater than 3 * (-6) = -18).
  That is why, when we encounter a negative number, we switch curr_max and curr_min.
  
  Everytime we encounter a situation where, curr_max * curr_element (running max product) < curr_element, we restart the running max product.
  Similary, if curr_min * curr_element (running min product) > curr_element, we restart the running min product.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_prod = INT_MIN;
        int curr_max = 1, curr_min = 1;
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
                swap(curr_max, curr_min);       //When the current element is negative, we swap curr_max and curr_min.
                                                //This ensures that we always get the max_product in curr_max and min_product in curr_min.
            
            curr_max = max(curr_max * nums[i], nums[i]);    
            curr_min = min(curr_min * nums[i], nums[i]);
            
            max_prod = max(max_prod, curr_max);
        }
        
        return max_prod;
    }
};
