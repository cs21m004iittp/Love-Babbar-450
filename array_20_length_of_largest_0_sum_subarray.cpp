//Discussion link: https://leetcode.com/discuss/general-discussion/1042029/find-length-of-the-largest-subarray-with-sum-0
//Question link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

// I did not find any link to solve this question in, so I just modified the given question to display the required result.

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_map<int, int> ump;
        int sum = 0, len, max_len = -1;
        bool flag = false;
        
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            
            if (sum == 0)
            {
                len = i;
                max_len = max(max_len, len);
                flag = true;
            }
            else if (ump.find(sum) != ump.end())
            {
                len = i - ump[sum] + 1;
                max_len = max(max_len, len);
                flag = true;
            }
            else
                ump[sum] = i+1;
        }
        
        cout << max_len << endl;
        
        return flag;
    }
};
