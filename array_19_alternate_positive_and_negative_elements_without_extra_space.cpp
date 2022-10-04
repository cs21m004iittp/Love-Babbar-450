//Question link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

/* The time complexity for the following solution is O(n^2) and hence does not pass the last few test cases of leetcode due to TLE error.
   However, this solution is without using any extra space and hence is worth knowing. */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0, j = 1;
        bool neg;
        while(i < n-1 && j < n)
        {
            neg = i % 2;
            if (!neg && nums[i] > 0 || neg && nums[i] < 0)
            {
                i++; j++;
            }
            else if (neg && nums[i] > 0)
            {
                while(j < n && !(nums[j] < 0))
                    j++;
                
                while (j > i)
                {
                    swap(nums[j], nums[j-1]);
                    j--;
                }
                
                i++;    j += 2;
            }
            else if (!neg && nums[i] < 0)
            {
                while(j < n && nums[j] < 0)
                    j++;
                
                while (j > i)
                {
                    swap(nums[j], nums[j-1]);
                    j--;
                }
                
                i++;    j += 2;
            }
        }
        
        return nums;
    }
};
