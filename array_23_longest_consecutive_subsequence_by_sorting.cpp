//Question link: https://leetcode.com/problems/longest-consecutive-sequence/

/*The task is to find the longest consecutive "subsequence", so a very naive method can be to sort the numbers.
  This way, the consecutive numbers come one after the other. So, it becomes easier to calculate the maximum length.
  But we need to ignore any duplicates in the subsequence (should not count them), so once a number is counted,
  all its duplicates are ignored before moving on to the next distinct number. */

//Time complexity: O(nlogn) + O(n) = O(nlogn)
//Space complexity: O(logn) (stack space for merge sort)
//Auxiliary space used: O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int len = 1, max_len = 1;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout << endl;
        
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i-1] == 1)
                len++;
            else
                len = 1;
            
            while(i+1 < n && nums[i] == nums[i+1])
                i++;
            
            max_len = max(max_len, len);
        }
        
        return max_len;
    }
};
