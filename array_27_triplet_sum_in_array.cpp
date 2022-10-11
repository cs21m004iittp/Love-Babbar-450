//Question link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0

/*The task is to search if there is a triplet in the array with the given sum.
  First, the array is sorted. Then, the outer for loop i takes up one element.
  The inner while loop has two pointers - j initialised to i+1 and k initialised to last element.
  If the sum of i,j,k is equal to the given sum, we found the triplet and hence return true.
  Otherwise, one of the two cases is possible the sum is less than the required sum, in which case
  we increment j pointer, and the sum is greater than the required sum, in which case we decrement
  the k pointer.
*/

//Time complexity: O(nlogn) + O(n^2) = O(n^2)   //Sorting takes O(nlogn) time and searching for the triplet requires O(n^2) time.
//Space complexity: O(1)  

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int sum)
    {
        //Your Code Here
        sort(arr, arr+n);               //Sorting the array brings down the searching complexity from O(n^3) to O(n^2)
        
        for (int i = 0; i < n; i++)     //The outer loop picks up one element at a time.
        {
            int j = i+1, k = n-1;
            while(j < k)                //The inner loop has two pointers and scans the array from after the element pointed to by the outer loop
            {
                if (arr[i] + arr[j] + arr[k] == sum)      //We found the triplet
                    return true;
                else if (arr[i] + arr[j] + arr[k] < sum)    //The required sum is greater than the found sum, so we increment j pointer
                    j++;
                else                                        //The required sum is less than the found sum, so we decrement k pointer
                    k--;
            }
        }
        
        return false;   //If the control reaches this part, it means we didn't find any triplet and hence return false.
    }

};
