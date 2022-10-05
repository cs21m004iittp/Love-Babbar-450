//Question link: https://leetcode.com/problems/longest-consecutive-sequence/

/*The idea is similar to sorting, but here instead of sorting, we store the elements in a hashset, which stores unique elements only
  and stores each element in O(1) time. Moreover, the lookup for each element also requires O(1) time.
  For every element in nums, we check if element-1 is present in hashset. If present, it means that it is not the first element of a sequence.
  Hence, we ignore that element.
  For some element, if element-1 is not present in the hashset, then we keep on checking for elements+1 continuously (and incrementing the length)
  untill all consecutive elements are exhausted for that first element. */

//Time complexity: O(n) (for storing in hashset) + O(n + n) (outer loop runs for n times, inner loop also accesses atmost n elements) = O(n)
//Auxiliary space used: O(n)  (Storing elements in the hashset)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int len = 1, max_len = 1, curr_num = nums[0];
        unordered_set<int> ust;
        for (int i = 0; i < n; i++)
            ust.insert(nums[i]);
        
        for (int i = 0; i < n; i++)
        {
            if (ust.find(nums[i] - 1) == ust.end())     //If the current element is the first element of a potential sequence
            {
                curr_num = nums[i];
                len = 1;
                
                while (ust.find(curr_num + 1) != ust.end())   //While there are consecutive elements in the sequence, increment the length
                {
                    curr_num += 1;
                    len += 1;
                }
            }
            
            max_len = max(max_len, len);
        }
        
        return max_len;
    }
};
