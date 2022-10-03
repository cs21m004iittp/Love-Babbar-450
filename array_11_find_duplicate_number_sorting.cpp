//Question link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i;
        
        for (i = 0; i < n; i++)
        {
            if (nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
        }
        
        for (i = 0; i < n; i++)
            if (nums[i] != i+1)
                break;
        
        return nums[i];
    }
};
