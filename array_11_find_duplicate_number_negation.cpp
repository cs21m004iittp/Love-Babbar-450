//Question link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i, ind;
        
        for (i = 0; i < n; i++)
        {
            ind = abs(nums[i]);
            if (nums[ind] < 0)
                break;
            else
                nums[ind] = -nums[ind];
        }
        
        return ind;
    }
};
