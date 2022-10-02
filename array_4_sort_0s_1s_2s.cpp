//Question link: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;
        int n = nums.size();
        int i;
        
        for (i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zeros++;
            else if (nums[i] == 1)
                ones++;
            else
                twos++;
        }
        
        i = 0;
        while(zeros--)
            nums[i++] = 0;
        
        while(ones--)
            nums[i++] = 1;
        
        while(twos--)
            nums[i++] = 2;
    }
};
