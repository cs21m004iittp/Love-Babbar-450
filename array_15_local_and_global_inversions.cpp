//Question link: https://leetcode.com/problems/global-and-local-inversions/

/* The original order should be [0, 1, 2, 3, 4...], i.e. the number i should be in position i. 
   So, we check if (A[i] < i-1 || A[i] > i+1). If that is the case, 
   then the number of global inversion must be more than the number of local inversions.
   
   For example, A[i] = 3, i = 1, at least one number that is smaller than 3 is kicked out from first 3 numbers.
   Let's consider A[0] = 0. Then, 1 and 2 are the numbers that occur after 3. Atleast one of them will be at a
   distance more than one places from 3. And hence, the intuition follows. */

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
            if (abs(nums[i] - i) > 1)
                return false;
        
        return true;
    }
};
