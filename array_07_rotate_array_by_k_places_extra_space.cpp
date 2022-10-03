// Link to Question: https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0 || n == 1) return;
        
        int temp_arr[k], j = 0;
        for (int i = n-k; i < n; i++)
            temp_arr[j++] = nums[i];
        
        for (int i = n-k-1; i >= 0; i--)
            nums[i+k] = nums[i];
        
        for (int i = 0; i < k; i++)
            nums[i] = temp_arr[i];
    }
};
