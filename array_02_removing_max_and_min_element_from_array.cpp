//Question link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2)   return n;
        
        int min_ind, min_val = INT_MAX, max_ind, max_val = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < min_val)
            {
                min_val = nums[i];
                min_ind = i;
            }
            
            if (nums[i] > max_val)
            {
                max_val = nums[i];
                max_ind = i;
            }
        }
        
        int mid = n / 2;
        vector<int> removals;
        int min_removals = INT_MAX;
        
        if (max_ind < min_ind)
            removals.push_back(min(min_ind+1, (n-max_ind)));
        
        if (min_ind < max_ind)
            removals.push_back(min(max_ind+1, (n - min_ind)));
        
        if (max_ind > min_ind && min_ind >= mid)
            removals.push_back(n - min_ind);
        
        if (min_ind > max_ind && max_ind >= mid)
            removals.push_back(n - max_ind);
        
        if (min_ind <= mid && max_ind > mid)
            removals.push_back(min_ind + 1 + (n - max_ind));
    
        if (max_ind <= mid && min_ind > mid) 
            removals.push_back(max_ind + 1 + (n - min_ind));
        
        for (int i = 0; i < removals.size(); i++)
        {
            cout << min_removals << " " << removals[i] << endl;
            if (removals[i] < min_removals)
                min_removals = removals[i];
        }
        
        return min_removals;
    }
};
