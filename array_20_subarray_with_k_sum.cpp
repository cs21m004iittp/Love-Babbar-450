//Question link: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, count = 0, req;
        
        unordered_map<int, int> ump;
        ump[sum]++;                     //sum when none of the values are considered
        
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            req = sum - k;
            if (ump.find(req) != ump.end())
                count += ump[req];
            
            ump[sum]++;
        }
        
        return count;
    }
};
