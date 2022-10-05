//Question link: https://leetcode.com/problems/top-k-frequent-elements/

/*The task is to find the top k elements with the most frequency of occurence.
  The time complexity of the solution should be better than O(nlogn), where n is the array size.
  
  The idea is to use a hashmap to store the unique elements and their frequency.
  A vector of vectors of length equal to the initial array size is created, where each element is
  pushed to the index that represent the frequency of that element.
  Then, the vector is searched from highest index (frequency) to lowest untill k elements are found.
  This is the implementation of bucket sort.
*/

//Time complexity: O(n) (storing frequencies in hashmap) + O(n) (transferring elements to the vector of vectors) +
//                 O(n + n) (searching for the top k frequent elements) (first n corresponds to the indexes in the vector,
//                 second n corresponds to the number of maximum number of elements collected) = O(n)
//Auxiliary space used: O(n) (hashmap) + O(n) vector of vectors = O(n)


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)     //Storing the unique elements along with their frequencies in a hashmap
            ump[nums[i]]++;
    
        vector<vector<int>> vec(n+1);
        for (auto x : ump)                      //Storing the elements corresponding to their frequencies in the vector of vectors
            vec[x.second].push_back(x.first);
        
        int count = 0;
        vector<int> ans;
        for (int i = n; i > 0; i--)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                ans.push_back(vec[i][j]);               //Extracting the top k frequent elements
                count++;  
            }

            if (count == k)
                break;
        }
        
        return ans;
    }
};
