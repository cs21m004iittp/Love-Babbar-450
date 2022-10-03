//Question link: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), less<vector<int>>());
        
        int n = intervals.size();
        vector<vector<int>> merged_intervals;
        merged_intervals.push_back({intervals[0][0], intervals[0][1]});
        int j = 0;
        
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= merged_intervals[j][1])
            {
                if (intervals[i][1] > merged_intervals[j][1])
                    merged_intervals[j][1] = intervals[i][1];
            }
            else
            {
                merged_intervals.push_back({intervals[i][0], intervals[i][1]});
                j++;
            }
        }
        
        return merged_intervals;
    }
};
