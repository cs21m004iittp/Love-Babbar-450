//Question link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0

/*The task is to find a triplet of numbers which sum up to the given sum.
  The brute force method is to run 3 loops and check every possible combination.
  If we find such pair, we return true. If all the possible combinations are being checked
  and we still can't find such a pair, then such a triplet is not possible and we return false.
*/

//Time complexity: O(n^3)     (3 loops required, one for the first element, one for the second element, one for the third element)
//Auxiliary space used: O(1)

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int sum)
    {
        //Your Code Here
        for (int i = 0; i < n; i++)             //Points to the first considered element
            for (int j = i+1; j < n; j++)       //Points to the second considered element
                for (int k = j+1; k < n; k++)   //Points to the third considered element
                    if (arr[i] + arr[j] + arr[k] == sum)    //If such a triplet is found, we return true.
                        return true;
                        
        return false;     //If the control reaches this line, that means, no such triplet is found and hence, we return false.
    }

};

//This is the unoptimised code and hence, does not pass all the test cases of Geeksforgeeks.
//It shows time limit exceeded for the last few test cases.
