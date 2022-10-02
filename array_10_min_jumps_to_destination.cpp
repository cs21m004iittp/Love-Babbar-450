// Question link: https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        
        for (int i = 0; i < n; i++)
            dp[i] = INT_MAX;
        dp[0] = 0;
        
        for (int i = 0; i < n; i++)
            for (int j = i+1; j <= i + nums[i] && j < n; j++)
                if (dp[j] > dp[i] + 1)
                    dp[j] = dp[i] + 1;
        
        return dp[n-1];
    }
};
