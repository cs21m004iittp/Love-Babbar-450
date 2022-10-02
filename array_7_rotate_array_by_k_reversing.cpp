// Link to Question: https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0 || n == 1) return;
        
        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.begin()+k);
        
        reverse(nums.begin()+k, nums.end());
    }
};
