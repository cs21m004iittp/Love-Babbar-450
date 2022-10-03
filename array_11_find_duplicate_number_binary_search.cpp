//Question link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n-1, mid, i, count;
        
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            
            count = 0;
            for (i = 0; i < n; i++)
                if (nums[i] <= mid)
                    count++;
            
            if (count <= mid)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return low;
    }
};
