//Question link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n, 0);
        
        int i = 0, j = 1;
        for (int ind = 0; ind < n; ind++)
        {
            if (nums[ind] > 0)
            {
                vec[i] = nums[ind];
                i += 2;
            }
            else
            {
                vec[j] = nums[ind];
                j += 2;
            }
        }
        
        return vec;
    }
};
