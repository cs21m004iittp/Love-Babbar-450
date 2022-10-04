//Question link: https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int len, max_len = 0;
        
        unordered_map<int, int> ump;
        ump[ones] = -1;
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                ones++;
            else
                ones--;
            
            if (ump.find(ones) != ump.end())
            {
                len = i - ump[ones];
                max_len = max(max_len, len);
                cout << max_len << endl;
            }
            else
                ump[ones] = i;
        }
        
        return max_len;
    }
};
