//Question link: https://leetcode.com/problems/majority-element-ii/

/*The task is to find all such elements which occur more than n/k times in the array, but in linear time and constant space.
  We take two potential candidates - major_elem1 and major_elem2, and their corresponding counts - count1 and count2;
  For every element we check if the element matches either of the two candidates. If yes, then we update the count for that
  candidate. If the count for a particular candidate is 0, then we update the potential candidate as the current candidate and
  set the count to be 1.
  After the first pass, we go for a second pass to count the frequencies of these two potential candidates. If the frequences of 
  either of these two is more than n/3, then they form part of the solution, otherwise not.
  
  This idea can be generalised to find elements which occur more than n/k times for a given n and k. We need a structure consisting of
  k-1 potential candidates and corresponding counts.
  We need a second pass to verify which of these form part of the answer.
  For the general case, Time complexity: O(nk) + O(n) = O(nk)
                        Auxiliary space used: O(k-1)    //The array of structure containing k-1 potential candidates.
  This is the Moore's Voting algorithm to find the majority element in an array.
*/

//Time complexity: O(n) + O(n) = O(n)
//Auxiliary space used: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        if (n == 1) 
        {
            ans.push_back(nums[0]);       
            return ans;                 //If there is only one element in the array, we return it.
        }
        
        int major_elem1 = INT_MIN, major_elem2 = INT_MIN;
        int count1 = 0, count2 = 0;
        
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == major_elem1)         //If the current element matches with either of the two potential candidates, we update count.
                count1++;
            else if (nums[i] == major_elem2)    
                count2++;
            else if (count1 == 0)             //If any candidate's count is 0, we update the current element as the potential candidate.
            {
                major_elem1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                major_elem2 = nums[i];
                count2 = 1;
            }
            else                            //If the current element is different from both the potential candidates, we decrement both their counts.
            {
                count1--;
                count2--;
            }
        }
        
        count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++)       //The second pass calculates the potential candidates' frequencies.
        {
            if (nums[i] == major_elem1)
                count1++;
            else if (nums[i] == major_elem2)
                count2++;
        }
        
        if (count1 > n/3)                 //If their respective frequencies are more than n/3, they form part of the answer.
            ans.push_back(major_elem1);
        if (count2 > n/3)
            ans.push_back(major_elem2);
        
        return ans;
    }
};
