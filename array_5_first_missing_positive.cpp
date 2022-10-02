//Question link: https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i, flag = 0;
        
        i = 0;
        while(i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        
        for (i = 0; i < n; i++)
            if (nums[i] != i+1)
            {
                flag = 1;
                break;
            }
        
        return (flag == 1) ? i+1 : n+1;
    }
};
