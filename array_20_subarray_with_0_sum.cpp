//Question link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_map<int, int> ump;
        int sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            
            if (sum == 0 || ump.find(sum) != ump.end())
                return true;
            else
                ump[sum]++;
        }
        
        return false;
    }
};
