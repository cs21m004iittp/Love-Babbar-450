//Question link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int curr_sum = 0, max_sum = INT_MIN;
        int i = 0; 
        
        while (i < n)
        {
            curr_sum += nums[i];
            
            if (max_sum < curr_sum)
                max_sum = curr_sum;
            
            if (curr_sum < 0)
                curr_sum = 0;
            
            i++;
        }
        
        return max_sum;
    }
};
