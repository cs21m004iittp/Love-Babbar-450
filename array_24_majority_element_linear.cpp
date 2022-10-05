//Question link: https://leetcode.com/problems/majority-element/

/*The task is to find the majority element but in linear time and constant space.
  We take a count variable and every time we encounter the same element we increment it
  and if we encounter a different element we decrement it. If the count reaches 0, then 
  we consider the current element as the majority element and repeat the process.
  The intuition is that, since the majority element occurs more than half the number of times
  the array size, so the count variable for the majority element will not become 0 (since there
  are not enough other elements to make it zero). Hence, at the end of one pass, we will have the majority element.
*/

//Time complexity: O(n)
//Auxiliary space used: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int major_elem = nums[0], count = 1;  //Declaring the first element to be the majority element and initializing the count as 1.
        
        for (int i = 1; i < n; i++)
        {
            if (count == 0)              //If count value reaches zero (it was probably not the majority element)
            {                       
                major_elem = nums[i];   //We update the majority element as the current element.
                count = 1;
            }
            else if (major_elem == nums[i])   //If we encounter the same element, we just increment the counter.
                count++;
            else
                count--;                      //The counter is decremented if a different element is encountered.
        }
        
        return major_elem;
    }
};
