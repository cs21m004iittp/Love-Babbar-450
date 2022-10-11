//Question link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

/*The task is to find if all elements of array2 are found in array1.
  Two hashmaps are taken - one each to count the occurrence of each distinct element in the two arrays.
  Then for every element of array2, it is checked if that elememt occurs equal to or more than the
  number of times in array1. If it does, then we continue, else we break and say that one or more elements
  from array2 is not present in array1.
*/

//Time complexity: O(n) + O(m) + O(m) = O(n)  //Maximum of m and n is considered
//Auxiliary space used: O(n) + O(m) = O(n)    //Hashmaps for the two arrays

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> ump1, ump2;
    
    for (int i = 0; i < n; i++)     //Hashmap1 contains elements of array1
        ump1[a1[i]]++;
    
    for (int i = 0; i < m; i++)     //Hashmap2 contains elements of array2
        ump2[a2[i]]++;
        
    bool flag = false;
    for (auto x : ump2)           //For every element in hashmap2...
    {
        if (ump1.find(x.first) != ump1.end() && ump1[x.first] >= x.second)    //If the element occurs in hashmap1 equal to or more than the number of times
            continue;                                                         //it occurs in hashmap2, we continue
        else                                                                  //Otherwise, we break and say that one or more elements of array2 is not present
        {                                                                     //in array1
            flag = true;
            break;
        }
    }
    
    if (flag)   return "No";
    
    return "Yes";
}
