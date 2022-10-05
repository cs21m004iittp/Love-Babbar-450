//Question link: https://leetcode.com/problems/top-k-frequent-elements/

/*The task is to find the top k elements with the most frequencies.
  The time complexity should be better than O(nlogn) where n is the array size.
  
  The idea is to store the unique elements along with their frequencies in a hashmap.
  Then a max_heap is created based on the frequencies of the elements. Lastly, the max_heap
  is popped k times to extract the k elements with the highest frequencies.
  
  This implementation uses heap sort.
*/

//Time complexity: O(n) (to store values in hashmap) + O(n) (to build max_heap using heapify) + 
//                 O(klogn) (to extract k elements from the max_heap) = O(klogn) (which is usually lesser than nlogn)
//Auxiliary space used: O(n) (hashmap) + O(n) (max_heap) = O(n)

class Solution {
public:
    struct heapNode                 //Defining a structure heapNode containing node_value and frequency
    {
        int node_val;
        int freq;
        
        heapNode(int a, int b)
        {
            node_val = a;
            freq = b;
        }
    };
    
    struct cmp
    {
        bool operator()(heapNode h1, heapNode h2)   //This is the comparator function to create a max_heap
        {
            if (h1.freq < h2.freq)
                return true;
            
            return false;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)     //Storing the unique values along with their frequencies in a hashmap
            ump[nums[i]]++;
    
        priority_queue<heapNode, vector<heapNode>, cmp> max_heap;
        for (auto x : ump)                                  //Building the max_heap
            max_heap.push(heapNode(x.first, x.second));
        
        vector<int> ans;
        while(k--)
        {
            ans.push_back(max_heap.top().node_val);     //Extracting the first k elements from max_heap
            max_heap.pop();
        }
        
        return ans;
    }
};
