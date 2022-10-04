//Question link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

class FindSumPairs {
public:
    vector<int> vec1, vec2;
    unordered_map<int, int> ump;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        
        sort(vec1.begin(), vec1.end());
        
        for (int i = 0; i < vec2.size(); i++)
            ump[vec2[i]]++;
    }
    
    void add(int ind, int val) {
        //remove the earlier value from the map
        ump[vec2[ind]]--;
        
        //add the particular value to the index of nums2
        vec2[ind] += val;
        
        //add the new value to the map
        ump[vec2[ind]]++;
    }
    
    int count(int tot) {
        int val, count = 0;
        
        for (int i = 0; i < vec1.size() && vec1[i] < tot; i++)
            if (ump.find(tot - vec1[i]) != ump.end())
                count += ump[tot-vec1[i]];
        
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
