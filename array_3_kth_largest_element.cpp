//Question link: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int quick_select (vector<int>& nums, int low, int high)
    {
        int pivot = high;
        int i = low-1, j = low;
        
        while (j <= high)
        {
            if (nums[j] <= nums[pivot] || j == pivot)
            {
                i++;
                if (i != j)
                    swap(nums[i], nums[j]);
            }
            
            if (j == pivot)
                pivot = i;
                
            
            j++;
        }
        
        return pivot;
    }
        
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = n-1;
        k = n - k;
        int pivot = -1;
        
        while (pivot != k)
        {
            pivot = quick_select(nums, low, high);
            
            if (pivot < k)
                low = pivot+1;
            else
                high = pivot-1;
        }
        
        return nums[pivot];
    }
};
