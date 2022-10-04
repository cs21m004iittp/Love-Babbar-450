//Question link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

class Solution{   
public:
    int getPairsCount(int arr[], int n, int key) {
        // code here
        sort(arr, arr+n);
         
        int i = 0, j = n-1, k;
        int count = 0;
        
        while (i < j)
        {
            if (arr[i] + arr[j] == key)
            {
                count += 1;
                
                k = i+1;
                while(k < j && arr[k] == arr[k-1])
                {
                    count += 1;
                    k++;
                }
                
                k = j-1;
                while(k > i && arr[k] == arr[k+1])
                {
                    count += 1;
                    k--;
                }
                
                i++;    j--;
            }
            else if (arr[i] + arr[j] < key)
                i++;
            else
                j--;
        }
        
        return count;
    }
};
