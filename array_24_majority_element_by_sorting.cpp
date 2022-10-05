//Question link: https://leetcode.com/problems/majority-element/

/*The task is to find the majority element which occurs more than half times the array size.
  The intuition is that, if we sort the array, no matter where the majority element starts from,
  it will always occupy the mid position of the array.
  For example, let's consider n = 5. So, the majority element has to occur at least 3 times.
  Case 1: [1, 2, 1, 3, 1] -> after sorting: [1, 1, 1, 2, 3] -> mid element = element at index 2 (0 based) is 1
          (which is clearly the majority element in this case).
  Case 2: [2, 3, 2, 1, 2] -> after sorting: [1, 2, 2, 2, 3] -> mid element = 2 (majority element here)
  Case 3: [3, 1, 3, 2, 3] ->after sorting: [1, 2, 3, 3, 3] -> mid element = 3 (majority element here)
*/

//Time complexity: O(nlogn)
//Auxiliary space used: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        sort (nums.begin(), nums.end());    //Sort the array
        
        return nums[n/2];     //Return the middle element
    }
};
