//Question link: 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        while (true)
        {
            if (nums[0] == nums[nums[0]])
                break;
            else
                swap(nums[0], nums[nums[0]]);
        }
        
        return nums[0];
    }
};
