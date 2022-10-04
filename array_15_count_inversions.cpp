//Question link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge_intervals(long long arr[], long long low, long long mid, long long high, long long &inversions)
    {
        long long i = low, j = mid+1;
        vector<long long> temp;
        
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                inversions += mid - i + 1;
                
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        
        while (j <= high)
        {
            temp.push_back(arr[j]);
            j++;
        }
        
        j = 0;
        for (i = low; i <= high; i++)
            arr[i] = temp[j++];
    }
    
    void merge_sort(long long arr[], long long low, long long high, long long &inversions)
    {
        if (low >= high)
            return;
        
        long long mid = low + (high - low) / 2;
        
        merge_sort(arr, low, mid, inversions);
        merge_sort(arr, mid+1, high, inversions);
        
        merge_intervals(arr, low, mid, high, inversions);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long local_inversions = 0;
        for (long long i = 0; i < N-1; i++)
            if (arr[i] > arr[i+1])
                local_inversions += 1;
        
        long long global_inversions = 0;
        merge_sort(arr, 0, N-1, global_inversions);
        
        return global_inversions;
    }

};
