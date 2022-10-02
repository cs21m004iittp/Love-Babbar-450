//Question link: https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int prev = -1;
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        vector<int> intersection;
        
        while (i < m && j < n)
        {
            if (nums1[i] == nums2[j])
            {
                if (nums1[i] != prev)
                {
                    intersection.push_back(nums1[i]);
                    prev = nums1[i];
                }
                
                i++; j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        
        return intersection;
    }
};
