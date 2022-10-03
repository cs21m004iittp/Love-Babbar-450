//Question link: https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0 || n == 1) return;
        
        int prev, temp, first_ind, curr_ind, next_ind, count = 0;
        prev = nums[0];
        first_ind = 0;
        curr_ind = 0;
        
        while (count < n)
        {
            do
            {
                next_ind = (curr_ind + k) % n;
                temp = nums[next_ind];
                nums[next_ind] = prev;
                prev = temp;
                curr_ind = next_ind;
                count++;
            }while(curr_ind != first_ind);
        
            prev = nums[++first_ind];
            curr_ind = first_ind;
        }
            
    }
};
