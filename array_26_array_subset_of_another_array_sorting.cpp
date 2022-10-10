//Question link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

/*The task is to find if all the elements of array 2 are present in array 1.
  The two arrays are sorted first. Then, the arrays are traversed and the following conditions are checked for-
  Condition 1: If the current elements of the two arrays are equal that means the current element of array 2 is
               present in array one. Both pointers are incremented by 1.
  Condition 2: If the current element of array 1 is less than current element of array 2, then the pointer for 
               array 1 is incremented.
  Condition 3: If the current element of array 1 is greater than the current element of array 2, that means the
               the current element of array 2 is not available in array 1, and hence the loop is broken.
  For returning we check if all the elements of array 2 has been traversed. If all elements have not been traversed,
  it means we encountered an element which was not in array 1 and hence we return "No". Otherwise, we return "Yes".
*/

//Time Complexity: O(nlogn) + O(mlogm) + O(m) = O(nlogn) //Sorting takes O(nlogn) time for array 1 (longer array) and O(mlogm) for array 2.
                                                         //Traversing takes O(m) time.
//Auxiliary space used: O(1) 

string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1, a1+n);
    sort(a2, a2+m);
    
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a1[i] == a2[j])     //Current element of array 2 is found in array 1
        {
            i++; j++;
        }
        else if (a1[i] < a2[j])   //Current element of array 1 is less than that of array 2
            i++;
        else                    //Current element of array 2 is not present in array 1
            break;  
    }
    
    if (j < m)
        return "No";
        
    return "Yes";
}
